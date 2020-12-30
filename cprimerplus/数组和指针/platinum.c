#include <stdio.h>
//#include <nodes/pg_list.h>
//#include <common/fe_memutils.h>

void test();

void swap(int *, int *);

int main() {
    float weight;
    float value;

    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");

    /* 获取用户输入： */
    scanf("%f", &weight);
    value = 1700 * weight * 14.5833;
    printf("Your weight in platinum is worth $%.2f.\n", value);

    test();

    int a = 1, b = 2;
    swap(&a, &b);
    return 0;
}

void test() {
    _Bool c99bool = 0;
    int *i;
    printf("The size of i is %zd\n", sizeof(*i));
}

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}