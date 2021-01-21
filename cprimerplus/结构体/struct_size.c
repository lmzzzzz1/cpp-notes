#include <stdio.h>

// Alignment requirements
// (typical 32 bit machine)

// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes

// structure A
typedef struct structa_tag
{
    char        c; // 1byte
    short int   s; // 2byte
    // 如果c之后立刻分配s，则s的寻址从奇数开始，cpu访问s将要用到两个读取周期
    // 因此填充一个字节，确保short int的2字节对齐
} structa_t;

// structure B
typedef struct structb_tag
{
    short int   s; // 2byte
    char        c; // 1byte
    int         i; // 4byte
    // 2+1+1+4 = 8
    // 在char后面填充一个byte，为了
} structb_t;

// structure C
typedef struct structc_tag
{
    char        c; // 1
    double      d; // 8
    int         s; // 4
    // 理论上可以是 1+7+8+4 = 20字节
    // 但是如果不是8的整数倍24的话
    // 试想structc_t数组第一个寻址到20字节
    // 第二个元素就从21开始
    // 那么第二个元素的double就要从20 + 1 + 7 = 28开始
    // 不是8的整数倍
    // 因此结构体的内存大小一定是 最大字段的整数倍
} structc_t;

// structure D
typedef struct structd_tag
{
    double      d; //8
    int         s; //4
    char        c; //1
} structd_t;

int main()
{
    printf("sizeof(structa_t) = %lu\n", sizeof(structa_t));
    printf("sizeof(structb_t) = %lu\n", sizeof(structb_t));
    printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));
    printf("sizeof(structd_t) = %lu\n", sizeof(structd_t));

    return 0;
}