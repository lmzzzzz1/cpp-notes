#include <stdio.h>
#include <stdlib.h>
#define NDEBUG
#include <assert.h>

#define NUM 40
void fillArray(double ar[], int n);
void showArray(const double ar[], int n);
int mycompare(const void *a, const void *b);
void errorFunc(void);

int main()
{
    double arr[NUM];
    fillArray(arr, NUM);

    showArray(arr, NUM);

    qsort(arr, NUM, sizeof(double), mycompare);

    showArray(arr, NUM);

    errorFunc();
}

void fillArray(double ar[], int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        ar[i] = (double)rand() / ((double)rand() + 0.1);
    }
}

void showArray(const double ar[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%9.4f ", ar[i]);
        if (i % 8 == 7)
        {
            putchar('\n');
        }
    }
    putchar('\n');
}

int mycompare(const void *a, const void *b)
{
    double *aa = (double *)a;
    double *bb = (double *)b;
    double cmp = *aa - *bb;
    if (cmp == 0)
    {
        return 0;
    }
    else if (cmp > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void errorFunc(void)
{
    int a = 1;
    for (; a < 10; ++a)
    {
        int b = a * a;
        assert(b < 10);
    }
}