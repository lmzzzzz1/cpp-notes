#include <stdio.h>
#include "const.h"
#include <stdlib.h>
#include <string.h>


int main111() {
    const int nochange;
    printf("nochange = %d", nochange);
//    nochange = 12; // 不行，不能给常量赋值，即使还没有初始化

//    const int nochange = 12; //这样可以

}

/**
 * 1. 在指针和形参声明中使用const
 */
void const_test()
{
    float val = 3.14f;
    float val2 = 3.24f;
    const float * pf = &val; // 指针指向的float是不可变的
    pf = &val2; // 但是pf本身可以指向其他的float（不管是不是const）

    const float * const ptr ; //指针和它所指向的值都不可变
    float const *i; //和const float *i相同
}

/**
 * 2. 在全局数据使用const
 */
const double PI = 3.14159265358979323846; //在源文件中定义
void test(){
    char *i ;
    i = (char *) malloc(strlen(QIEZI)+1); //在头文件中定义
}
