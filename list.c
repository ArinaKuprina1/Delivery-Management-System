/**************/
/*   list.c   */
/**************/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


//////////////////////////////////////////
// Init
// Aim:		create new list
// Input:	pointer to the list structure
// Output:	TRUE if succeeded
//////////////////////////////////////////
BOOL L_init(LIST* pList)
{
	if (pList == NULL)
		return False;	// no list to initialize

	pList->head.next = NULL;
	pList->head.key = NULL;
	return True;
}

int L_length(LIST* list) {
	int count = 0;
	NODE* current = &list->head; // Start from the head of the list

	// Traverse the linked list and count nodes
	while (current->next != NULL) {
		count++;
		current = current->next;
	}

	return count;
}
/////////////////////////////////////////////////////////////////
// Insert
// Aim:		add new node
// Input:	pointer to the node BEFORE the place for the new one
//			a value to be stored in the new node
// Output:	pointer to the new node
/////////////////////////////////////////////////////////////////
NODE* L_insert(NODE* pNode, DATA value, int(*compare)(const void*, const void*))
{
	NODE* temp, * current;
	int check = 0;

	if (!pNode)
		return NULL;
	current = pNode;
	// A ,  ,C , D
	temp = (NODE*)malloc(sizeof(NODE));	// new node
	if (temp == NULL)
		return NULL;
	temp->key = value;

	if (pNode->next == NULL)
	{
		pNode->next = (NODE*)malloc(sizeof(NODE));
		if (!pNode->next)
			return NULL;
		pNode->next->key = value;
		pNode->next->next = NULL;
	}
	else if (compare(temp->key, pNode->next->key) < 0)
	{
		temp->next = pNode->next; // Point the new node to the current head
		pNode->next = temp;
		//pList->head = *temp;
	}
	else
	{
		current = current->next;
		while (current->next != NULL)
		{
			check = 0;
			if (compare(temp->key, current->key) > 0 && compare(temp->key, current->next->key) < 0)
			{
				temp->next = current->next;
				current->next = temp;
				check = 1;
				break;
			}
			current = current->next;
		}
		if (!check)
		{
			temp->next = current->next; // in the end
			current->next = temp;
		}
	}

	return temp;
}


//////////////////////////////////////////////////////////////
// Delete
// Aim:		erase node
// Input:	pointer to the node BEFORE the node to be deleted 
// Output:	TRUE if succeeded
//////////////////////////////////////////////////////////////
BOOL L_delete(NODE* pNode, void(*freeKey)(void*))
{
	NODE* tmp;

	if (!pNode || !(tmp = pNode->next))
		return False;

	pNode->next = tmp->next;
	if (freeKey)
		freeKey(tmp->key);
	free(tmp);
	return True;
}


/////////////////////////////////////////////////////////
// Find
// Aim:		search for a value
// Input:	pointer to the node to start with 
//			a value to be found
// Output:	pointer to the node containing the Value
/////////////////////////////////////////////////////////
const NODE* L_find(NODE* pNode, DATA Value, int(*compare)(const void*, const void*))
{
	const NODE* temp = NULL;
	while (pNode != NULL)
	{
		if (compare(pNode->key, Value) == 0)
		{
			temp = pNode;
			break;
		}
		pNode = pNode->next;
	}
	return temp;
}


////////////////////////////////////////////////
// Free (additional function)
// Aim:		free the list memory
// Input:	pointer to the list structure
// Output:	TRUE if succeeded
////////////////////////////////////////////////
BOOL L_free(LIST* pList, void(*freeKey)(void*))
{
	NODE* tmp;

	if (!pList) return False;

	for (tmp = &(pList->head);
		L_delete(tmp, freeKey););
	return True;
}


////////////////////////////////////////////////
// Print (additional function)
// Aim:		print the list content (assume the DATA is int)
// Input:	pointer to the list structure
// Output:	a number of the printed elements
////////////////////////////////////////////////
int L_print(LIST* pList, void(*print)(const void*))
{
	NODE* tmp = pList->head.next;
	int		c = 0;

	if (!pList) return 0;

	printf("\n");
	for (; tmp; tmp = tmp->next, c++)
		print(tmp->key);
	printf("\n");
	return c;
}