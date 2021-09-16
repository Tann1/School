#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>


struct Node {
	int val;
	struct Node* next;
};

struct linked_list {
	struct Node* head; 
};


static inline struct linked_list *
ll_create(void)
{
	return (struct linked_list *) malloc(sizeof(struct linked_list)); //returns NULL if it can't allocate the desired memory space 
}


static inline int
ll_destroy(struct linked_list *ll)
{
	if (ll != NULL && ll->head == NULL) {
		free(ll);
		return 1;
	}
	return 0;	
}


static inline void
ll_add(struct linked_list *ll, int value)
{
	struct Node* temp;

	if (ll == NULL) {			//if empty
		printf("Linked List is empty must create list first\n");
		return;
	}
	temp = (struct Node *) malloc(sizeof(struct Node));
	temp->val = value;
	temp->next = NULL;
	if (ll->head == NULL) {		//if the list is created but is still empty 
		ll->head = temp;
		return;
	}
	
	temp->next = ll->head;		//since temp will be the new head update the current head to be temp's next
	ll->head = temp;		//now replace current head with temp (the new head)
}
static inline int
ll_length(struct linked_list *ll)
{
	int length = 0;
	struct Node* temp = ll->head;	
	while (temp != NULL) {
		length++;
		temp = temp->next;
	}	
	return length;
}

static inline bool
ll_remove_first(struct linked_list *ll)
{
	struct Node* temp; 

	if (ll == NULL || ll->head == NULL)	//if empty
		return false;		
	temp = ll->head;			//capture the head in a temp variable
	ll->head = ll->head->next;		//update the current head to be head's next node (the new head)
	free(temp);				//deallocate the current head from the heap 
	return true;
}

static inline int
ll_contains(struct linked_list *ll, int value)
{
	int pos = 1;
	struct Node* temp = NULL;

	if (ll != NULL)
		temp = ll->head;
	while (temp != NULL) {
		if (temp->val == value) 	//first check to see if the current node val is the one we are looking for
			return pos;		//if it is then return it's position
		temp = temp->next;		//otherwise move to the next node to check there 
		pos++;				//update the respective position as well
	}
	return 0;
}
#endif
