#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}NODE;

void list_creat(NODE *head, int nums)
{
	int i;
	NODE *node;
	NODE *list;

	list = head;
	head->next = NULL;

	for(i=0; i<nums; i++){
		node = (NODE *)malloc(sizeof(NODE));
		node->next = NULL;
		node->prev = NULL;
		node->data = 0;

		list->next = node;
		node->prev = list;
		list = list->next;
	}
	return ;
}

int list_insert(NODE *head, int data, int location)    //min of location is 0
{
	if(!head || location < 0){
		return -1;
	}
	int i;
	NODE * list;
	NODE *node;

	list = head;
	node = (NODE*)malloc(sizeof(NODE));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;

	for(i=0; i<location; i++){
		list = list->next;
	}
	node->next = list->next->next;
	list->next->next->prev = list->next;
	list->next = node;
	node->prev = list;

	return 0;
}



int list_delete(NODE *head, int location)    //min of location is 1
{
	if(!head || location < 1){
		return -1;
	}
	int i;
	NODE *list;
	
	list = head;
	
	for(i=0; i<locaiton-1; i++){
		list = list->next;
	}
	free(list->next);
	list->next->next->prev = list;
	list->next = list->next->next;

	return 0;
}

NODE *list_addr(NODE *head, int nums)
{
	if(!head){
		return NULL;
	}

	int i;
	NODE *list;

	list = head;
	for(i=0; i<nums; i++){
		list = list->next;		
	}
	
	return list;
}

int list_exchange(NODE *head, int nums)    //min is 1.
{
	if(!head || nums < 1){
		return -1;
	}

	int i;
	NODE *list;
	NODE *node00, *node01;

	list = head;
	for(i=0; i<nums; i++){
		list = list->next;
	}
	head01 = list->next;
	list->next->next->prev = list;
	list->next = list->next->next;

	list->prev->next = head01;
	head01->prev = list->prev;
	head01->next = list;
	list->prev = head01;
	
	return 0;
}

int list_sort(NODE *head, int nums)
{
	if(!head){
		return -1;
	}

	int i, j;
	NODE *list;
	
	for(i=0; i<nums; i++){
		for(j=0; j<nums-(i+1); j++){
			if(list_addr(head,j) < list_addr(head, j+1)){
				list_exchange(head,j);
			}
		}
	}
	return 0;
}

