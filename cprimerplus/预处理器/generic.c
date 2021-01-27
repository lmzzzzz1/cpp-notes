#include <stdio.h>
#include <math.h>
#include <tgmath.h>

#define RAD_TO_DEG (180/(4*atanl(1)))

/* 泛型平方根 */
#define SQRT(X) _GENERIC((X),\
long double: sqrtl,\
default: sqrt,\
float: sqrtf)(X)
/* 泛型正弦函数，单位是度 */
#define SIN(X) _GENERIC((X), \
long double: sinl((X)/RAD_TO_DEG), \
default:sin((X)/RAD_TO_DEG), \
float: sinf((X)/RAD_TO_DEG))

int main(void)
{
    float x = 45.0f;
    double xx = 45.0;
    long double xxx = 45.0L;
    long double y = sqrt(x);
    long double yy = sqrt(xx);
    long double yyy = sqrt(xxx);
}