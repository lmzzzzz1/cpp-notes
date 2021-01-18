#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
/**
 * restrict关键字表示只能用于指针
 * 用于 优化部分代码
 * 表明该指针是访问对象的 唯一 且 初始 的方式。
 */
static void test_restrict_()
{
    int ar[10];
    int * restrict restar = (int*)malloc(10*sizeof(int));
    int *par = ar;
    printf("ar[0] = %d\n",ar[0]);

    for (int i = 0; i < 10; i++) {
        par[i] += 5;
        restar[i] += 5;
        ar[i] *= 2;
        par[i] += 3;
        restar[i] += 3;
        /**
         * 编译器可以将restar[i] += 5;和restar[i] += 3;优化为
         * restar[i] += 8;
         * 而不能优化par[i] += 8;
         * 因为par不是 初始且唯一 的访问方式
         */
    }

}

void memcpy_test(void * restrict s1,void * restrict s2, size_t n)
{
    /**
     * s1和s2都是restrict的指针，那么说明
     * s1和s2指向的位置必然是不同的
     * 从而达到了限制参数s1和s2不同的效果
     */
}

int main(void)
{
    test_restrict_();
    return 0;
}