#include "list.h"


void ll_print(struct linked_list*);

int main(void)
{
	struct linked_list* list = ll_create();	
	
	
	ll_add(list, 12);
	ll_add(list, 13);
	ll_print(list);
	printf("size of list: %d\n", ll_length(list));
	printf("pos of 12: %d\n", ll_contains(list, 12));
	ll_remove_first(list);
	ll_print(list);
	ll_remove_first(list);
	printf("list destroyed: %d\n", ll_destroy(list));
	return 0;
}

void ll_print(struct linked_list* ll) {
	int pos = 1;
	struct Node* temp = ll->head;	
	printf("printing Linked List\n");
	if (temp == NULL) 
		printf("Linked List is empty, nothing to print!\n");
	while (temp != NULL) {
		printf("pos %d: %d\n", pos, temp->val);
		temp = temp->next;
		pos++;
	}
}

