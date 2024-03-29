#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64
#define MAX_NUM_BG_PROCESSES 64


static pid_t global_child_id;
static int exec_type = -1;

char **tokenize(char *line, int *type_of_exec, int* number_of_cmds);
char *generateFilepath(const char *command);
void error_msg();
char **parse_cmd(char **, int*);
void print(char **); //testing purposes
void normal_exec(char **);
void background_exec(char **, pid_t*);
void series_exec(char **);
void parallel_exec(char **, int);
void handle_sigint(int);


int main(int argc, char* argv[]) {
	char  line[MAX_INPUT_SIZE];
	pid_t bg_processes[MAX_NUM_BG_PROCESSES];            
	char  **tokens;              
	int exit_code, type_of_exec, number_of_cmds, wstatus, bg_idx, freed_procs;
	bool background_proc = false;
	pid_t bg_child_id, child_id;
	struct sigaction sa_sigint;

	//initalize data to zero in both sigaction struct
	memset(&sa_sigint, 0, sizeof(sa_sigint));
	
	sa_sigint.sa_handler = handle_sigint;
	sa_sigint.sa_flags = SA_RESTART;

	sigaction(SIGINT, &sa_sigint, NULL);



	FILE* fp;
	if(argc == 2) {
		fp = fopen(argv[1],"r");
		if(fp < 0) {
			printf("File doesn't exists.");
			return -1;
		}
	}

	bg_idx = - 1;
	freed_procs = 0;
	while(1) {	
		
		/* BEGIN: TAKING INPUT */


		bzero(line, sizeof(line));
		if(argc == 2) { // batch mode
			if(fgets(line, sizeof(line), fp) == NULL) { // file reading finished
				argc = 0;
				printf("$ ");
				//fflush(stdout);
				scanf("%[^\n]", line);
				getchar();
			}
			if (argc)
				line[strlen(line) - 1] = '\0';
		} else { // interactive mode
		    //if (print_prompt) //need for series being terminated by control signal
			printf("$ ");
			//fflush(stdout);
			scanf("%[^\n]", line);
			getchar();
		}
		
				
		
		//printf("Command entered: %s (remove this debug output later)\n", line);
		/* END: TAKING INPUT */
		if (!strlen(line)) //line is empty then start over
			continue; 
		line[strlen(line)] = '\n'; //terminate with new line

		
		tokens = tokenize(line, &type_of_exec, &number_of_cmds);

        //do whatever you want with the commands, here we just print them

		switch(type_of_exec) {
			case 0: //normal process
				if (!strcmp(tokens[0], "exit")) { //if it's exit
					killpg(getpid(), SIGKILL);
					exit(EXIT_SUCCESS);
				}
				normal_exec(tokens);
				break;
			case 1:	//background process
				background_proc = true;
				background_exec(tokens, &bg_child_id);
				bg_processes[++bg_idx] = bg_child_id;
				break;
			case 2:
				series_exec(tokens);
				//print(tokens);
				break;
			case 3:
				parallel_exec(tokens, number_of_cmds);
				break;
			
		}

		if (background_proc) {
			for (int i = 0; i < bg_idx + 1; ++i) {
					child_id = waitpid(bg_processes[i], &wstatus, WNOHANG);
					//printf("child_id: %d\n", child_id);
					if (WIFEXITED(wstatus) && child_id != -1 && child_id != 0) {
						printf("Shell: Background process finished\n");
						freed_procs++;
					}
				}	
		}
		bg_idx -= freed_procs;
		//printf("bg_idx: %d\n", bg_idx);
		freed_procs = 0;
		if (bg_idx == -1)
			background_proc = false;

		
	
		// Freeing the allocated memory	
		for(int i=0;tokens[i]!=NULL;i++){
			free(tokens[i]);
		}
		free(tokens);

	}
	return 0;
}


char **tokenize(char *line, int *type_of_exec, int* number_of_cmds)
{
  char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
  char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
  int i, tokenIndex = 0, tokenNo = 0;
  *type_of_exec = 0;	// 0 - normal, 1 - background, 2 - series, 3 - parallel
  *number_of_cmds = 0;

  for(i =0; i < strlen(line); i++){
    char readChar = line[i];

    if (readChar == ' ' || readChar == '\n' || readChar == '\t'){
      token[tokenIndex] = '\0';
	  if (!strcmp(token, "&"))
	  	*type_of_exec = 1;
	  else if (!strcmp(token, "&&")) {
		if (*type_of_exec == 0)
			*type_of_exec = 2;
		++*number_of_cmds;
	  }	
	  else if (!strcmp(token, "&&&")) {
		  if (*type_of_exec == 0)
		  	*type_of_exec = 3;
		++*number_of_cmds;
	  }
      if (tokenIndex != 0){
		
		tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
		strcpy(tokens[tokenNo++], token);
		tokenIndex = 0; 
      }
    } else {
      	token[tokenIndex++] = readChar;
    }
  }

  exec_type = *type_of_exec; //for signal handling purposes
	
  free(token);
  if (*type_of_exec == 1)
	tokens[tokenNo - 1] = NULL; //get rid of the & 
  tokens[tokenNo] = NULL ;
  ++*number_of_cmds;
  return tokens;
}

char *generateFilepath(const char *command) {
	char *filepath = (char *)malloc(sizeof(char) * (strlen("/bin/") + strlen(command)));
	
	*filepath = '\0'; //initialize it to empty string
	strcat(filepath, "/bin/");
	strcat(filepath, command);

	return filepath;
}

void error_msg() {
	printf("Shell: Incorrect command\n");
}

char **parse_cmd(char **tokens, int* idx) {
	char **cmds = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
	int i = 0, index = *idx;
	
	while (tokens[index] != NULL) {
		if (!strcmp(tokens[index], "&&") || !strcmp(tokens[index], "&&&"))
			break;
		cmds[i++] = tokens[index++];
	}
	cmds[i] = NULL;
	*idx = index;

	return cmds;
}

void print(char **line) {

	printf("cmd: ");
	for (int i = 0; line[i] != NULL; ++i) {
		printf("%s ", line[i]);
	}
	printf("\n");
}

void normal_exec(char **tokens) {
	int exiterr, wstatus;
	char* filepath;
	if (!strcmp(tokens[0], "cd")) { //Change directory code
		if (tokens[2] != NULL) {
				error_msg();
				return;
			}
			exiterr = chdir(tokens[1]);
			if (exiterr == -1)
				error_msg();
			return;
		}
	else if (!strcmp(tokens[0], "exit")) {
		if (tokens[1] != NULL) {
			error_msg();
			return;
		}
		exit(EXIT_SUCCESS);
	}
		pid_t proc_id = fork();
		global_child_id = proc_id;
		if (proc_id < 0) {
			error_msg();
		}
		else if (proc_id == 0) {
			//printf("Current Process: %d Current Process's Parent: %d\n", getpid(), getppid());
			//printf("Current Process: %d Current Process's Group: %d\n", getpid(), getpgid(getpid()));
			filepath = generateFilepath(tokens[0]);
			exiterr = execv(filepath, tokens);
			error_msg();
			free(filepath);
			exit(EXIT_FAILURE);
		}
		else {
			proc_id = waitpid(proc_id, &wstatus, 0);
		}
}

void background_exec(char **tokens, pid_t* proc_id) {
	int exiterr, wstatus;
	char* filepath;

	if (!strcmp(tokens[0], "cd")) { //Change directory code
			if (tokens[2] != NULL) {
				error_msg();
				return;
			}
			exiterr = chdir(tokens[1]);
			if (exiterr == -1)
				error_msg();
			return;
		}
	else if (!strcmp(tokens[0], "exit")) {
		if (tokens[1] != NULL) {
			error_msg();
			return;
		}
		exit(EXIT_SUCCESS);
	}
		*proc_id = fork();

		if (*proc_id < 0) {
			error_msg();
		}
		else if (*proc_id == 0) {
			
			filepath = generateFilepath(tokens[0]);
			exiterr = execv(filepath, tokens);
			error_msg();
			free(filepath);
			exit(EXIT_FAILURE);
		}
}

void series_exec(char **tokens) {
	char* filepath;
	char** cmd;
	int i = 0, exiterr, wstatus;
	pid_t proc_id, child_id;

	while(tokens[i] != NULL){
		cmd = parse_cmd(tokens, &i);
		i++;
		if (!strcmp(cmd[0], "cd")) { //Change directory code
			if (cmd[2] != NULL) {	//Passing 2 arguments to cd 
				error_msg();
				continue;
			}
			exiterr = chdir(cmd[1]);
			if (exiterr == -1)
				error_msg();
			continue;
		}
		else if (!strcmp(cmd[0], "exit")) {
		if (cmd[1] != NULL) {
			error_msg();
			continue;
		}
		exit(EXIT_SUCCESS);
	}
		proc_id = fork();
		global_child_id = proc_id;
		if (proc_id < 0)
			error_msg();
		else if (proc_id == 0) {
			filepath = generateFilepath(cmd[0]);
			exiterr = execv(filepath, cmd);
			error_msg();
			free(filepath);
			exit(EXIT_FAILURE);
		}
		else {
			//printf("waiting: %d cmd: %s\n", proc_id, cmd[0]);
			child_id = waitpid(proc_id, &wstatus, 0);
			if (WIFSIGNALED(wstatus)) {//if child exits cuz of sig kill
				return; //stop the loop don't execute further series processes in queue.
			//printf("exited: %d child_id: %d\n", wstatus, child_id);
			}
		}
	}

}
/*
	pid = pgid its the leader
	fork children
	pgid == ppid
	sleep 120
	shell -> pid 10 pgid 10
	sleep -> pid 11 pgid 10

	shell -> pgid -> pgid(ppid)
	kkill(current_id == shell id)
	shell -> pgid -> 10
*/
void parallel_exec(char ** tokens, int num_of_cmds) {
	char* filepath;
	char** cmd;
	int i = 0, exiterr, wstatus;
	pid_t proc_id, child_id;

	while(tokens[i] != NULL){
		cmd = parse_cmd(tokens, &i);
		i++;
		if (!strcmp(cmd[0], "cd")) { //Change directory code
			if (cmd[2] != NULL) {	//Passing 2 arguments to cd 
				error_msg();
				continue;
			}
			exiterr = chdir(cmd[1]);
			if (exiterr == -1)
				error_msg();
			continue;
		}
		else if (!strcmp(cmd[0], "exit")) {
		if (cmd[1] != NULL) {
			error_msg();
			continue;
		}
		exit(EXIT_SUCCESS);
	}
		proc_id = fork();
		global_child_id = proc_id;
		if (proc_id < 0)
			error_msg();
		else if (proc_id == 0) {
			filepath = generateFilepath(cmd[0]);
			exiterr = execv(filepath, cmd);
			error_msg();
			free(filepath);
			exit(EXIT_FAILURE);
		}
	}

	for (int i = 0; i < num_of_cmds; ++i)
		wait(&wstatus);

}

void handle_sigint(int sig) {
		pid_t proc_grp;

		if (global_child_id) { //here means I'm in the parent process
			proc_grp = getpgid(getpid());
			setpgid(getpid(), getpgid(getppid()));
			//printf("type of exec: %d\n", exec_type);
			//printf("(child_proc: %d) current proc: %d current proc group: %d", global_child_id, getpid(), getpgid(getpid()));
			//if (exec_type != 1) //only kill processes that are in the foreground not the background when the sig int is given.
			killpg(proc_grp, SIGKILL);
			setpgid(0, 0);
			write(1, "\n", 1);
			exec_type = -1; //reset
		}
		else { //when global_child_id == 0 basically there is no child
			write(1, "\n$ ", 3);
			fflush(stdout);
		}
		global_child_id = 0;
}

