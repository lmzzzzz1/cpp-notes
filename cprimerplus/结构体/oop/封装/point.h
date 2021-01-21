// Header
struct Point;  // forward declared for encapsulation
Point* Point__create(int x, int y);  // equivalent to "new Point(x, y)"
void Point__destroy(Point* self);  // equivalent to "delete point"
int Point__x(Point* self);  // equivalent to "point->x()"
int Point__y(Point* self);  // equivalent to "point->y()"
/**
 * 在头文件中只告诉了用户有这么一个结构体
 * 可以创建
 * 可以销毁
 * 可以get值
 * 具体的实现全在.c文件里
 */