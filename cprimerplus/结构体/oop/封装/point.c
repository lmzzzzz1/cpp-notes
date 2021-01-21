#include "point.h"

// Source file
typedef struct Point {
   int x;
   int y;
}Point;

// Constructor (without allocation)
void Point__init(Point* self, int x, int y) {
  self->x = x;
  self->y = y;
 }

// Allocation + initialization (equivalent to "new Point(x, y)")
Point* Point__create(int x, int y) {
   Point* result = (Point*) malloc(sizeof(Point));
   Point__init(result, x, y);
   return result;
}

// Destructor (without deallocation)
void Point__reset(Point* self) {
}

// Destructor + deallocation (equivalent to "delete point")
void Point__destroy(Point* point) {
  if (point) {
     Point__reset(point);
     free(point);
  }
}

// Equivalent to "Point::x()" in C++ version
int Point__x(Point* self) {
   return self->x;
}

// Equivalent to "Point::y()" in C++ version
int Point__y(Point* self) {
   return self->y;
}