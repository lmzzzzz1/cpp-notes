 // Header
class Point {
 public:
    Point(int x, int y);
    ~Point();
    int x() const;
    int y() const;
 private:
    const int x_;
    const int y_;
 };

 // Source file
 Point::Point(int x, int y) : x_(x), y_(y) {}
 Point::~Point() {}
 int Point::x() const { return x_; }
 int Point::y() const { return y_; }