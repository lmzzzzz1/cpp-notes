#include <stdio.h>
#include <stdarg.h>

// 1.必须提供一个函数原型，至少有一个形参和一个省略号
double sum(int n, ...);

int main(void)
{
    printf("%f",sum(5,1.0,3.0,2.0,4.0,8.0));
}

double sum(int n, ...)
{
    // 2. 声明一个va_list变量
    va_list arg_list;
    // 3. 用宏把...拷贝到va_list变量中
    va_start(arg_list, n);

    double res;
    for (size_t i = 0; i < n; i++)
    {   
        // 4. 通过宏访问va_list变量的每一项
        res += va_arg(arg_list, double);
    }
    // 5. 清理工作
    va_end(arg_list);
    return res;
}