#include <stdio.h>

void test_volatile_() {
    volatile int locl;
    volatile int *ploc;//指向的int是volatile的
    int *volatile ploc1;

    int x = 100;
    int val1, val2;
    /**
     * 编译器优化
     * 编译器会注意到x并未改变，
     * 于是从寄存器中（而不是原始内存中）取出x的值来赋给val2
     */
    val1 = x;
    val2 = x;
}