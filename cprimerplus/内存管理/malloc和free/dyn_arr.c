#include <stdio.h>
#include <stdlib.h>

void test_malloc(void) {
    // 申请一个数组
    double *p;
    p = (double *) malloc(30 * sizeof(double));
    // 这样一来，p就是一个大小是30的double数组了

    free(p);
}

int main() {
    double *ptd;
    int max, number;
    int i = 0;
    puts("What is the maximum number of type double entries?");
    if (scanf("%d", &max) != 1) {
        puts("Number of not correctly entered --bye.");
        exit(EXIT_FAILURE);
    }
//    ptd = (double *)malloc(max * sizeof(double));
    ptd = (double *)calloc(max, sizeof(double));
    ptd = realloc(ptd, 2 * max * sizeof(double));

    if (ptd == NULL){
        puts("Memory allocation failed. Goodbye!");
        exit(EXIT_FAILURE);
    }

    // ptd指向现有max个元素的double数组
    puts("Enter the values (q to quit): ");
    while (i < max && scanf("%lf", &ptd[i]) == 1) {
        ++i;
    }
    printf("Here are your %d entries:\n", number = i);
    for (i = 0; i < number; ++i) {
        printf("%7.2f", ptd[i]);
        if (i % 7 == 6) {
            putchar('\n');
        }
    }
    if (i % 7 != 0) {
        putchar('\n');
    }
    puts("Done.");
    free(ptd);

    return 0;
}