#include "addressbook.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    char input[MAX_INPUT];
    char* splitInput[10];
    char *tokens;
    int i = 0;
    int moves;
    char * fileName;
    char *ptr;
    TelephoneBookList * linkedlist = createTelephoneBookList();
    int id;
    char * name;
    char * phone;

    splitInput[0] = "";

    printf("-----------------------------------------------------------------\nStudent name: Sam Jacobson\nStudent number: s3491184\nAdvanced Programming Techniques, Assignment Two, Semester 1, 2016\n-----------------------------------------------------------------\n\n");
    /* if an argment is passed in on the command line the load command will run */
    if (argv[1] != NULL)
    {
        printf("> Opening the file %s\n", argv[1]);
        linkedlist = commandLoad(argv[1]);
    }

    while(TRUE)
    {
        printf("Enter your command: ");
        fgets(input, sizeof(input), stdin);
        if(input[strlen(input) - 1] != '\n')
        {
            printf("> Input was too long, try again. \n\n");
            readRestOfLine();
        }
        input[strlen(input) - 1] = '\0';
        tokens = strtok(input, ", ");
        i = 0;
        while(tokens != NULL)
        {
            splitInput[i] = tokens;
            tokens = strtok(NULL, ", ");
            i++;
        }

        if (strcmp(splitInput[0], "load") == 0)
        {
            fileName = strtok(splitInput[1], "\n");
            printf("> Opening the file %s\n", fileName);


            if (linkedlist->head == NULL)
            {
                linkedlist = commandLoad(fileName);   
            }
            else
            {
                printf("> The list is unloading \n");
                freeTelephoneBookList(linkedlist);
                linkedlist = commandLoad(fileName);   
            }
            
        }
        if (strcmp(splitInput[0], "quit") == 0)
        {
            printf("> Goodbye. \n\n");
            commandUnload(linkedlist);
            free(linkedlist);
            return EXIT_SUCCESS;
        }
        if (strcmp(splitInput[0], "display") == 0)
        {
            commandDisplay(linkedlist);
        }
        if (strcmp(splitInput[0], "unload") == 0)
        {
            commandUnload(linkedlist);
            printf("> list unloaded\n");

        }
        if (strcmp(splitInput[0], "reverse") == 0)
        {
            commandReverse(linkedlist);
        }
        if (strcmp(splitInput[0], "forward") == 0)
        {   
            moves = strtol(splitInput[1], &ptr, 10);

            if (linkedlist->head != NULL)
            {
                commandForward(linkedlist, moves);
            }

        }
        if (strcmp(splitInput[0], "backward") == 0)
        {   
            moves = strtol(splitInput[1], &ptr, 10);
            if (linkedlist->head != NULL)
            {
                commandBackward(linkedlist, moves);
            }
        }

        if (strcmp(splitInput[0], "insert") == 0)
        {   
            id = strtol(splitInput[1], &ptr, 10);
            name = splitInput[2];
            phone = splitInput[3];
            commandInsert(linkedlist, id, name, phone);
            
        }
        if (strcmp(splitInput[0], "find") == 0)
        {   
            name = splitInput[1];
            commandFind(linkedlist, name);
            
        }
        if (strcmp(splitInput[0], "delete") == 0)
        {   
            if (linkedlist->head != NULL)
            {
                commandDelete(linkedlist);
            }
            else
            {
                printf("> can not delete\n");
            }
           
            
        }
        if (strcmp(splitInput[0], "save") == 0)
        {   
            fileName = strtok(splitInput[1], "\n");
            commandSave(linkedlist, fileName);
            
            
        }
    }

    printf("> Goodbye. \n\n");

    return EXIT_SUCCESS;
}