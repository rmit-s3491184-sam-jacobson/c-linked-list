#include "addressbook_list.h"

TelephoneBookList * createTelephoneBookList()
{
    TelephoneBookList * linkedList = malloc(sizeof(TelephoneBookList));

    /* Test if the OS was able to give the program memory for the new linkedList */
    if(linkedList == NULL)
    {
        return FALSE;
    }

    if(linkedList != NULL)
    {
        linkedList->head = NULL;
        linkedList->tail = NULL;
        linkedList->current = NULL;
        linkedList->size = 0;
    }

    return linkedList;
}


void freeTelephoneBookList(TelephoneBookList* list)
{
	TelephoneBookNode * node = list->head;
    while(node != NULL)
    {
        TelephoneBookNode * temp = node;
        node = node->nextNode;

        free(temp);
        list->size--;
    }
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

TelephoneBookNode * createTelephoneBookNode()
{
	TelephoneBookNode * node = malloc(sizeof(TelephoneBookNode));

	/* Test if the OS was able to give the program memory for the new node */
	if(node == NULL)
    {
        return FALSE;
    }

        node->id = 0;
        strcpy(node->name, "");
        strcpy(node->telephone, "");
        node->previousNode = NULL;
        node->nextNode = NULL;


    return node;
}

void freeTelephoneBookNode(TelephoneBookNode * node)
{
    free(node);
}

Boolean insert(TelephoneBookList * list, TelephoneBookNode * node)
{
	if(list->head == NULL)
	{
		list->head = list->tail = list->current = node;
	}
	else
	{
		list->tail->nextNode = node;
		node->previousNode = list->tail;
		list->tail = node;
	}
	list->size++;
	return TRUE;
}

Boolean forward(TelephoneBookList * list, int forward)
{
    return FALSE;
}

Boolean backward(TelephoneBookList * list, int backward)
{
    return FALSE;
}

Boolean delete(TelephoneBookList * list)
{
    TelephoneBookNode * cur = list->current;
    TelephoneBookNode * temp;
    /*deletes from the start of the list*/
    if (cur->previousNode == NULL)
    {
        temp = cur->nextNode;
        list->head = cur->nextNode;
        list->current = temp;
        temp->previousNode = NULL;
        list->size--;
        freeTelephoneBookNode(cur);
        return TRUE;
    }
    /*deletes from the end of the list*/
        if (cur->nextNode == NULL)
    {
        temp = cur->previousNode;
        list->tail = cur->previousNode;
        list->current = temp;
        temp->nextNode = NULL;
        list->size--;
        freeTelephoneBookNode(cur);

        return TRUE;
    }
    /*deletes from the middle of the list*/
    if ((cur->nextNode != NULL)
        &&(cur->previousNode != NULL))
    {
        temp = cur->previousNode;
        temp->nextNode = cur->nextNode;
        temp = cur->nextNode;
        temp->previousNode = cur->previousNode;
        list->current = temp->previousNode;
        list->size--;
        freeTelephoneBookNode(cur); 
        return TRUE; 
    }

    return FALSE;
}

TelephoneBookNode * findByID(TelephoneBookList * list, int id)
{
    return NULL;
}

TelephoneBookNode * findByName(TelephoneBookList * list, char * name)
{
    return NULL;
}
