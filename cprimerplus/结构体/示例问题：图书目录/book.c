#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *s_gets(char *, int);

#define MAXTITL 41
#define MAXAUTL 31
typedef struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
} Book;

typedef struct ListNode {
    int val;
    struct ListNode * next;
}ListNode;

int main(void) {
    Book harrypotter;
    // 或者可以写
    struct book library;

    printf("Please enter the book title:\n");
    // scanf("%s", harrypotter.title);
    s_gets(harrypotter.title, MAXTITL);
    printf("Now enter the author.\n");
    s_gets(harrypotter.author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &harrypotter.value);
    printf("%s: \"%s\" ($%.2f)\n", harrypotter.title, harrypotter.author, harrypotter.value);
    return 0;

}

char *s_gets(char *st, int n) {
    char *res;
    char *find;
    res = fgets(st, n, stdin);
    if (res) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return res;
}

void test_struct(void) {
    struct book *qwer;
    qwer = (struct book *) malloc(sizeof(struct book));
    free(qwer);

    Book new_book = {"Harry potter",
                     "JK",
                     3.99f};
    qwer = &new_book;
    printf("%s,\n%s,\n,%.2f\n", qwer->title, qwer->author, qwer->value);
}