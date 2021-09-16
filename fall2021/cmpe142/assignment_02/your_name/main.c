#include "list.h"


void ll_print(struct linked_list*);

int main(void)
{
	struct linked_list* list = ll_create();	
	
	ll_add(&list, 12);
	ll_add(list, 13);
	ll_print(list);

	ll_remove_first(list);
	ll_remove_first(list);
	ll_print(list);		
	return 0;
}

void ll_print(struct linked_list* ll) {
	int pos = 1;
	
	printf("printing Linked List\n");
	if (ll == NULL) 
		printf("Linked List is empty, nothing to print!\n");
	while (ll != NULL) {
		printf("pos %d: %d\n", pos, (int) ll->val);
		ll = ll->next;
		pos++;
	}
}
