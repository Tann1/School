#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>


struct linked_list {
	double val;
	struct linked_list* next;
};

static inline struct linked_list *
ll_create(void)
{
	struct linked_list* ll = (struct linked_list *) malloc(sizeof(struct linked_list)); //returns NULL if it can't allocate the desired memory space 
	ll->val = HUGE_VAL; 						       //indicates that the node is empty 
	return ll;
}

/*
static inline int
ll_destroy(struct linked_list *ll)
{

}
*/

static inline void
ll_add(struct linked_list *ll, int value)
{
	struct linked_list* temp;

	if (ll == NULL) {			//if empty
		printf("Linked List is empty must create list first\n");
		return;
	}
	if (ll->val == HUGE_VAL) {		//if the list is created but is still empty relative to its value 
		ll->val = (double) value;
		ll->next = NULL;
		return;
	}
	temp = ll_create();
	temp->val = (double) value;
	temp->next = NULL;
	temp->next = ll;			//let current head become temp's next so temp becomes current head
	ll = temp;				//update ll to temp since temp is current head now 
}

static inline int
ll_length(struct linked_list *ll)
{
	int length = 0;
	
	while (ll != NULL) {
		length++;
		ll = ll->next;
	}	
	return length;
}

static inline bool
ll_remove_first(struct linked_list *ll)
{
	struct linked_list* temp; 

	if (ll == NULL || ll->val == HUGE_VAL)	//if empty
		return false;		
	temp = ll;				//capture the head in a temp variable
	ll = ll->next;				//update the current head to be head's next node (the new head)
	free(temp);				//deallocate the current head from the heap 
	return true;
}

static inline int
ll_contains(struct linked_list *ll, int value)
{
	int pos = 1;

	while (ll != NULL) {
		if (ll->val == (double) value) 	//first check to see if the current node val is the one we are looking for
			return pos;		//if it is then return it's position
		ll = ll->next;			//otherwise move to the next node to check there 
		pos++;				//update the respective position as well
	}
	return 0;
}
#endif
