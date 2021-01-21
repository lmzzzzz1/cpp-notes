// shape.h
class Shape {
public:
/**
 * c++ virtual虚函数用来实现多态
 * 虚函数的调用取决于指向或者引用的对象的类型，而不是指针或者引用自身的类型
 */
   virtual ~Shape() {}
   virtual const char* name() const = 0;
   virtual int sides() const  = 0;
};

// square.h
class Square : public Shape {
 public:
    Square(int x, int y, int width, int height)
        : x_(x), y_(y), width_(width), height_(height) {}
    virtual ~Square() {}

    const char* name() const override { return "Square"; }
    int sides()  const override { return 4; }

    int x() const { return x_; }
    int y() const { return y_; }
    int width() const { return width_; }
    int height() const { return height_; }

private:
    int x_;
    int y_;
    int width_;
    int height_;
};