#include <stdio.h>

const int MAX_LENGTH = 256;

int main(int argc, char* args[]) 
{
	char* progname = args[0];
	char  buffer[MAX_LENGTH];
	while (fgets(buffer, sizeof(buffer), stdin) > 0)
		printf("progname: %s, argc: %d, %s", progname, argc, buffer);
	printf("Done\n");
	return 0;
}
