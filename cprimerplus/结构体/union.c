#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union hold {
    int digit;
    double bigfl;
    char letter;
};

int main()
{
    union hold fit;
    union hold save[10];
    union hold * ptr;
    printf("%lu\n",sizeof(fit));
    fit.digit = 23;
    printf("%lu\n",sizeof(fit));
    fit.bigfl = 2.0; // 清除23，存储2.0，占用8字节
    printf("%lu\n",sizeof(fit));
    fit.letter = 'p'; // 清除2.0，存储p，占用1字节
    printf("%lu\n",sizeof(fit));
}