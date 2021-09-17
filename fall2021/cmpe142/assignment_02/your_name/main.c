#include "list.h"
#include <stdio.h>
#include <stdlib.h>


void ll_print(struct linked_list*);
void ll_fill(struct linked_list*, unsigned int, unsigned int);
void ll_remove_n_amt(struct linked_list*, unsigned int);
void ll_contains_n_amt(struct linked_list*, unsigned int, unsigned int);

int main(void)
{
	struct linked_list* list = ll_create();	
	const unsigned int MAX_RANGE = 200;	
	unsigned int len = 100;

	ll_fill(list, len, MAX_RANGE);
	ll_print(list);
	ll_contains_n_amt(list, len, MAX_RANGE);
	ll_remove_n_amt(list, len);	
	ll_print(list);
	ll_remove_n_amt(list, len/2);	
	return 0;
}

void ll_print(struct linked_list* ll) {
	int pos = 1;
	struct Node* temp = ll->head;	
	printf("printing Linked List\n");
	printf("total items in the list: %d\n", ll_length(ll));
	if (temp == NULL) 
		printf("Linked List is empty, nothing to print!\n");
	while (temp != NULL) {
		printf("pos %d: %d\n", pos, temp->val);
		temp = temp->next;
		pos++;
	}
}

void ll_fill(struct linked_list* list, unsigned int length, unsigned int range) {	//fill out length nodes with max range of max
	for (unsigned int i = 0; i < length; ++i) 
		ll_add(list, (int) rand() % range);
} 


void ll_remove_n_amt(struct linked_list* list, unsigned int amount) {
	unsigned int success = 0, failure = 0;

	for (unsigned int i = 0; i < amount; ++i) {
		if (ll_remove_first(list))
			success++;
		else
			failure++;
	}
	printf("total deletion requested: %u\n", amount);
	printf("successfully deleted: %u unsucessful deletion: %u\n", success, failure);
}

void ll_contains_n_amt(struct linked_list* list, unsigned int length, unsigned int range) {
	unsigned int success = 0, failure = 0;
	int pos;
	int ran_val;

	printf("total requested contains(): %u with a max range of: %u\n", length, range);
	for (unsigned int i = 0; i < length; ++i) {
		ran_val = (int) rand() % range;
		pos = ll_contains(list, ran_val);
		if (pos) {							//meaning it found it in the lis
			printf("found %d at pos: %d\n", ran_val, pos);
			success++;
		}
		else
			failure++;
	}
	printf("total existed values found: %u not found: %u\n", success, failure);
}
