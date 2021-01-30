#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    printf("The size of Item is: %d\n", sizeof(Item));
    int length = 120;
    Item item;
    printf("The size of item is: %d\n", sizeof(item));
    printf("The address of the item is: %p\n", &item);

    int *i = NULL;

    Queue line;
    Item temp;
    char ch;
    InitializeQueue(&line);
    puts("Testing the Queue interface. Type a to add a value,");
    puts("Type d to delete a value, and type q to quit.");

    while ((ch = getchar()) != 'q')
    {
        if (ch != 'a' && ch != 'd')
            continue;
        if (ch == 'a')
        {
            printf("Integer to add:\n");
            scanf("%d", &temp);
            if ((!QueueisFull(&line)))
            {
                printf("Putting %d into queue\n", temp);
                EnQueue(temp, &line);
            }
            else
                puts("The queue is full!");
        }
        else
        {
            if ((QueueIsEmpty(&line)))
                puts("Noting to delete!");
            else
            {
                DeleteQueue(&line, &temp);
                printf("delete %d from queue line!", temp);
            }
        }
        printf("%d items in the line.\n", QueueItemCount(&line));
        puts("Type a to add a value, d to delete a value, and type q to quit.");
    }

    EmptyTheQueue(&line);
    return 0;
}