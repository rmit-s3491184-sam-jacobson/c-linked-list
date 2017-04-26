#include "commands.h"

TelephoneBookList * commandLoad(char * fileName)
{
    TelephoneBookList * linkedList = createTelephoneBookList();
    TelephoneBookNode * node = createTelephoneBookNode();
    char line[LINE_LENGTH];
    char *splitLineArray[50];
    char *splitLine;
    char *ptr;
    FILE * fp;
    int i;
    fp = fopen(fileName, "r");
    if(fp == NULL)
    {
        printf("> Error: Unable to find the specified file. \n");
        return linkedList;
    }

    printf("> Loading the file ...\n");
    while (fgets(line, sizeof(line), fp)) 
    {
        node = createTelephoneBookNode();
        if (line[0] != '#')
        {   
            i = 0;
            splitLine = strtok(line, " ,");
            while (splitLine != NULL)
            {
                splitLineArray[i] = splitLine;
                splitLine = strtok(NULL, " ,");
                i++;
            }

            splitLineArray[2] = strtok(splitLineArray[2], "\n");
            node->id = strtol(splitLineArray[0], &ptr, 10);
            strcpy(node->name, splitLineArray[1]);
            strcpy(node->telephone, splitLineArray[2]);

            if ((strlen(node->name) <= NAME_LENGTH - NULL_SPACE) 
                && (strlen(node->telephone) == TELEPHONE_LENGTH - NULL_SPACE) 
                && (node->id < 10000) && (node->id > NODE_MINIMUM_ID)
                && (i == 3))
            {
                insert(linkedList, node); 
            }
            else
            {
                printf("> Error: The specified file is in the wrong format and cannot be loaded.\n");
                freeTelephoneBookList(linkedList);
                return linkedList;
            }
                
            
            
        }
    }
    printf("> %u phone book entries have been loaded from the file.\n", linkedList->size);
    fclose(fp);
    printf("> Closing the file.\n"); 
    return linkedList;
}

void commandUnload(TelephoneBookList * list)
{
    freeTelephoneBookList(list);
    
}

void commandDisplay(TelephoneBookList * list)
{   
    TelephoneBookNode * node = list->head;
    int i = 1;

    printf("------------------------------------------------------\n");
    printf("| Pos | Serial | ID | Name               | Telephone |\n");

    printf("------------------------------------------------------\n");
    if (list->head == NULL)
    {
        printf("|                                                    |\n");
    }
    while(node != NULL)
    {
        if (list->current == node)
        {
            printf("| cur |%-8d|%-4d|%-20s|%-11s|\n",i, node->id, node->name, node->telephone);
        }
        else
        {
        printf("|     |%-8d|%-4d|%-20s|%-11s|\n",i, node->id, node->name, node->telephone);
        }
        i++;
        node = node->nextNode;
    }
    printf("------------------------------------------------------\n");
    printf("| Total phone book entries: %-15u          |\n", list->size);
    printf("------------------------------------------------------\n");



}

void commandForward(TelephoneBookList * list, int moves)
{
    int i;
    TelephoneBookNode * temp;
    temp = list->current;
    for (i = 0; i < moves; i++)
    {

        if (list->current->nextNode == NULL)
        {
            printf("> can not move out forward of bounds of list\n");
            list->current = temp;
            break;
        }
        list->current = list->current->nextNode;
    }
}

void commandBackward(TelephoneBookList * list, int moves)
{
    int i;
    TelephoneBookNode * temp;
    temp = list->current;
    for (i = 0; i < moves; i++)
    {
        if (list->current->previousNode == NULL)
        {
            printf("> can not move out back of bounds of list\n");
            list->current = temp;
            break;
        }
        list->current = list->current->previousNode;
    }
}

void commandInsert(TelephoneBookList * list, int id, char * name, char * telephone)
{
    TelephoneBookNode * node = createTelephoneBookNode();
    TelephoneBookNode * temp = list->head;

    while(temp != NULL)
    {
        if (id == temp->id)
        {
            printf("> ID already exists\n");
            free(node);
            return;
        }
        temp = temp->nextNode;
    }
    if ((strlen(name) <= NAME_LENGTH - NULL_SPACE) 
        && (strlen(telephone) == TELEPHONE_LENGTH - NULL_SPACE) 
        && (id < 10000) && (id > NODE_MINIMUM_ID))
    {
        node->id = id;
        strcpy(node->name, name);
        strcpy(node->telephone, telephone);
        insert(list, node);
    }
    else
    {
        printf("> invalid input\n");
        free(node);
    }

    
}

void commandFind(TelephoneBookList * list, char * name)
{
    TelephoneBookNode * temp = list->head;
    while(temp != NULL)
    {
        if (strcmp(name, temp->name) == 0)
        {
            list->current = temp;
            return;
        }
        temp = temp->nextNode;
    }
    printf("> Error unable to find %s\n", name);
}

void commandDelete(TelephoneBookList * list)
{
    if (delete(list))
    {
        printf("> node deleted\n");
    }
    else
    {
        printf("> node not delteted\n");
    } 
}

void commandReverse(TelephoneBookList * list)
{

    
    TelephoneBookNode * temp, * current;

    current = list->head;
    while(current != NULL)
    {
        temp = current->nextNode;
        current->nextNode = current->previousNode;
        current->previousNode = temp;
        current = temp;
    }
    temp = list->head;
    list->head = list->tail;
    list->tail = temp;

}

void commandSave(TelephoneBookList * list, char * fileName)
{
    FILE * fp;
    TelephoneBookNode * node = list->head;
    fp = fopen(fileName, "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    while(node != NULL)
    {
        fprintf(fp,"%d, %s, %s\n", node->id, node->name, node->telephone);
        node = node->nextNode;
    }

    fclose(fp);

}

void commandSortName(TelephoneBookList * list)
{

}

void commandSortRandom(TelephoneBookList * list)
{

}
