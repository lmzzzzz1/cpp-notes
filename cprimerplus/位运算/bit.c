#include <stdio.h>
#include <stdlib.h>
/**
 * C语言里面
 * 二进制表示：前缀为0b或0B
 * 八进制表示：前缀为0
 * 十六进制表示：前缀为0x或者0X
 */
// 16bit 掩码
#define MASK 0xff

void test()
{
    char flag = 0b00010001;
    flag &= 0xff;
    flag &= MASK;
}

void test2()
{
    //按照由低阶到高阶 blue, green, red的字节来存储
    unsigned long color = 0x002a162f;
    unsigned char red, green, blue;
    red = color & MASK;
    green = (color >> 8) & MASK;
    blue = (color >> 16) & MASK;
    printf("RGB is (%d,%d,%d)\n", red, green, blue);

}

int main()
{
    char fu1 = 0b10000011;
    printf("%d\n", fu1);
    fu1 >>= 1;
    printf("%d\n", fu1);

    test2();
}