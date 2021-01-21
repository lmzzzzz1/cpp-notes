#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 20
const char *msgs[5] = {
        "1",
        "2",
        "3",
        "4",
        "5"
};

struct names {
    char first[LEN];
    char last[LEN];
};

struct pnames {
    char * first;
    char * last;
};

struct guy {
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(void) {
    struct guy fellow = {
            .favfood = "fish",
            .job = "doctor",
            .income = 100000.0f,
            .handle = {
                    .first = "James",
                    .last = "Harden"
            }
    };
    /**
     * 结构体中指针和普通变量的区别
     */
    struct names myname;
    struct pnames mypname;
    scanf("%s", myname.first);
    scanf("%s", mypname.first);
    /**
     * 语法上没有问题。
     * 但是names会直接分配内存给first，first是一个char数组，往里写入新的值是ok的
     * 而pnames只给first分配了内存，而first是一个指针，指向哪里是不确定的，因此
     */

    return 0;
}