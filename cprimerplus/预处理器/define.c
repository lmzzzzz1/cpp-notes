#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// 普通用法，用于替换变量，简单函数（注意，函数中不能使用自增和自减）
#define ONE 1
#define MEAN(X, Y) (((X) + (Y)) / 2)
#define SQUARE(X) ((X) * (X))
#define PR(X) printf("The result is %d.\n", X)

// 字符串替换
#define PSQR(x) printf("The result of " #x " is %d.\n", x)

// ##可以作为粘合剂
#define XNAME(n) x##n
#define PRINT_XN(n) printf("x" #n " = %d\n", x##n)

// 变参宏：...和__VA_ARGS__
// 省略号只能代替最后的参数，不能中间出现省略号
#define PR(X, ...) printf("Message " #X ": "__VA_ARGS__)

void test_define();
void test_define2();
void test_define3();
void test_define4();

int main()
{
    test_define4();
}

void test_define()
{
    const int one = 1;
    int array[ONE];
    int array2[one];
}

void test_define2()
{
    int x = 5;
    int z;
    printf("x is %d.\n", x);
    z = SQUARE(x);
    PSQR(z);
    PSQR(MEAN(x, z));

    z = SQUARE(2);
    PSQR(z);

    PSQR(SQUARE(x + 2));
    PSQR(100 / SQUARE(2));

    printf("x is %d.\n", x);
    printf("Evaluating SQUARE(++x)");
    PSQR(SQUARE(++x));

    printf("x is %d.\n", x);
}

void test_define3()
{
    int XNAME(1) = 1;
    int XNAME(2) = 2;

    PRINT_XN(1);
    PRINT_XN(2);
}

void test_define4()
{
    double x = 48;
    double y;
    y = sqrt(x);
    PR(1, "x = %g\n", x);
    PR(2, "x = %.2f, y = %.4f\n", x, y);
}
