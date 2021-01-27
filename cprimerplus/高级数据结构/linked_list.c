#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TITLELEN 40
char *s_gets(char *st, int n);
struct film
{
    char title[TITLELEN];
    int rate;
    struct film *next;
};

int main(void)
{
    struct film *head = NULL;
    struct film *pre, *cur;
    char input[TITLELEN];

    puts("Enter film title: ");

    while ((s_gets(input, TITLELEN)) != NULL &&
           input[0] != '\0')
    {
        cur = (struct film *)malloc(sizeof(struct film));
        if (head == NULL)
        {
            head = cur;
        }
        else
        {
            pre->next = cur;
        }
        strcpy(cur->title, input);
        puts("Enter film rate <0-10>: ");
        scanf("%d", &cur->rate);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to exit): ");
        pre = cur;
    }

    // show
    if (head == NULL)
        printf("No Data input.");
    else
        printf("Here is the data input:");
    cur = head;
    while (cur != NULL)
    {
        printf("Movie: %s, Rating: %d\n", cur->title, cur->rate);
        cur = cur->next;
    }

    // free
    while (head != NULL)
    {
        cur = head;
        head = cur->next;
        free(cur);
    }
    printf("Bye!\n");
}

char *s_gets(char *st, int n)
{
    char *res;
    char *find;
    res = fgets(st, n, stdin);
    if (res)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return res;
}
