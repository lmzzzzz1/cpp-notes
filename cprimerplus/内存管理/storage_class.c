#include <stdio.h>

/* 
 C语言内存模型分为三种机制
 1. 作用域（表示可见性）
 2. 链接 （表示字段在文件和程序范围可用）
 3. 存储期 （表示生命周期）
 
 C通过这三种机制给所有的变量定义了多种存储方案，分别为：
 自动 auto
 寄存器 register
 静态外部链接 extern
 静态内部链接 static
 静态无链接 static
 */

// =================================================================
// 1. 自动变量 auto
// auto不会初始化，只会赋给他一个垃圾值
int auto_main(void)
{   
    auto int plox; // == int plox
    // auto is storage-class specifer, very different from c++
    // 块中默认的存储类别就是auto，所以一般不显示的写出来
    int x = 30;
    {
        int x = 20; // 覆盖了原来的x
    }
    while(x++ < 33) 
    {
        int x = 100; // 这又是一个新的x，作用域仅在块里
        x++;
        printf("x = %d\n", x);
    }

    return 0;
}

// =================================================================
// 2. 寄存器变量register
static int register_main()
{   
    // register变量和auto变量很像，初始值都是垃圾值
    // 会试图向编译器申请存放在寄存器中，从而不能得到他的内存地址
    // 寄存器能放的数据类型有限，比如double可能就不行
    register int x = 0;
    // int *p = &x; // 错

    register double d = 1.0;
    return 0;
}

// =================================================================
// 3. 静态变量static
// 块作用域静态变量
void static_main()
{
    int fade = 1;
    static int stay = 1;
    printf("fade = %d, stay = %d\n", fade++, stay++);

}
// 文件作用域静态变量, 普通的外部变量对全程序可见
// 而static的外部变量只对同一个翻译单元内的函数可见（必须include才能使用）
static int svil = 1;


// =================================================================
// 4. 外部变量extern
int Errupt; // 外部变量会自动初始化为0
int a = 1;
// int b = 2 * a; // 外部变量只能使用常量表达式来初始化
double Up[100];
// extern int Coal; // 引用型声明一个外部变量，虽然外部变量对全程序可见，但使用之前必须要先extern声明一下。

void extern_main()
{
    extern int Errupt; // 其实这两条extern声明可以忽略，因为extern具有文件作用域
    extern double Up[]; // 不需要声明大小，因为前面已经定义过了

    Errupt += Up[0];
    printf("extern int Errupt is initial as %d\n", Errupt);
}


// ===============================main==============================
int main(){
    auto_main();
    register_main();    

    static_main();
    static_main();

    extern_main();
}

