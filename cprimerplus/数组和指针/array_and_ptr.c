#include <stdio.h>

#define PI 3.14159265358979323846
#define MONTHS 12
#define SIZE 4

typedef int arr4[4];
typedef arr4 arr3x4[3];

void initial(void);
void array_and_ptr();
int array_as_parameter(const int[], int);
void vla(void);

// 声明一个N维的数组可以有以下两种方式
void sum4d(int ar[][12][12][12], int rows);
void sum5d(int(*ar)[12][2][2][12], int rows);

// C语言支持变长数组
void vla_sum(int rows, int cols, int array[rows][cols]);
void vla_sum_no_para(int, int, int arr[*][*]);

int main(int argc, char *argv[]) {
    //    initial();
    array_and_ptr();
}

void initial(void) {
    int powers[] = {1, 2, 4, 6, 8, 16, 32, 64};
    for (int i = 0; i < sizeof(powers) / sizeof(powers[0]); ++i) {
        printf("Month %2d has %d days.\n", i + 1, powers[i]);
    }

    // 指定初始化器
    int arr[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
    for (int i = 0; i < MONTHS; ++i) {
        printf("%2d\n", arr[i]);
    }
}

void array_and_ptr() {
    short dates[SIZE];
    short *pti;
    short index;
    double bills[SIZE];
    double *ptf;
    pti = dates;
    ptf = bills;
    for (index = 0; index < SIZE; ++index) {
        printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
    }
}

int array_as_parameter(const int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}


void multi_array() {
    int zippo[4][2] = {{2, 4},
                       {6, 8},
                       {1, 3},
                       {5, 7}};
    // 已知int*和zippo[0]等价
    // 又因为[]的优先级要高于*，所以要括起来（*p）表示p是一个指针
    // p必须声明为指向一个数组的指针
    int(*p)[2] = zippo;

    // pax先和[2]结合，所以pax是一个数组，数组中每个元素都是 int *
    int *pax[2];
}

void multi_ptr() {
    int x = 20;
    const int y = 23;
    int *p1 = &x;
    const int *p2 = &y;
    const int **pp2;
    p1 = p2; // 不安全，把const赋给非const指针，相当于可以通过新的指针来改变const指针所指向的内容

    p2 = p1;   // 有效，可以把非const指针赋给const指针，前提是只进行一级解引用
    pp2 = &p1; // 允许，但不安全，嵌套指针类型赋值，这会导致const限定符失效
    const int n = 13;
    *pp2 = &n; // 有效，这样就会导致p1指向n
    *p1 = 10;  // 也有效，但是这样n的值也会改变了（但是根据前面的代码，n是常量）
}

int sum1(const int *junk, int n) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += junk[i];
    }
    return res;
}

int sum2(int (*junk)[4], int rows) {
}

int sum3(int junk[][4], int rows) {
}

int sum4(arr3x4 ar, int rows) {

}

void multi_ptr_as_parameter() {
    // add all
    int junk[3][4] = {{2,  3,  4,  5},
                      {6,  7,  8,  9},
                      {10, 11, 12, 13}};
    int i, j;
    int total = 0;
    for (int k = 0; k < 3; ++k) {
        total += sum1(junk[k], 4);
    }

}


void vla(void) {
    int quarters = 4;
    int regions = 4;
    double sales[regions][quarters];
}

void vla_sum(int rows, int cols, int array[rows][cols]) {

}
