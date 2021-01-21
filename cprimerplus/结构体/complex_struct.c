#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test()
{
    // 下面是一些比较复杂的声明
    int board[8][8];
    int **ptr;
    int *risks[10];  // risks是一个数组，数组中每一个元素都是int*
    int(*rusks)[10]; // risks是一个指针，指向一个int[10]的数组
    int *off[3][4];  // off是一个二维数组，其中数组中的每一项都是一个int*
    int(*uuf)[3][4]; // uuf是一个指针，指向int[3][4]的数组
    int(*uof[3])[4]; // uof是一个长度为3的数组，数组中每一项都是指向int[4]的指针
}

/*
 * 复杂声明的原则
 * 1. 数组名后面的[]和函数名后面的()具有相同的优先级，
 * 他们都比*（解引用运算符）的优先级要高
 * 2. []和()的优先级相同，从左往右结合
 */
void test_functions()
{
    // 复杂声明函数
    char *fump(int);
    char fff(int);
    char (*frump)(int); //指向函数的指针，该函数的返回类型是char，参数是int
    frump = fff;
    char (*flump[3])(int); //flump是一个数组，数组中每一个元素都是一个指针，指向一个char f(int)函数
}

void test_typedef()
{
    typedef int arr5[5]; //arr5 -> int[5]
    arr5 myarr = {1, 2, 3, 4, 5};

    typedef arr5 *p_arr5; // p_arr5 -> arr5*
    p_arr5 my_p = &myarr;

    typedef p_arr5 arrp10[2]; // arrp10 -> p_arr5[10]
    arrp10 my_arrp10 = {&myarr, &myarr};
}

// 函数指针作为函数的参数
// fp:function pointer
void show(void (*fp)(char *),  char * str);