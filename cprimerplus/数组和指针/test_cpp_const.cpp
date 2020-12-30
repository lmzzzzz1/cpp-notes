#include <iostream>

int main()
{
    const int y = 0;
    const int *p2 = &y;
    int *p1;
    p1 = p2; // cpp直接报错，但是C语言可能只给警告
}