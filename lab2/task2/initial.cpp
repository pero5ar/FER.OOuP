#include <iostream>
#include <assert.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

struct Shape {
    enum EType { circle, square, rhomb };
    EType type_;
};

struct Circle {
    Shape::EType type_;
    double radius_;
    Point center_;
};

struct Square {
    Shape::EType type_;
    double side_;
    Point center_;
};

struct Rhomb {
    Shape::EType type_;
    double side_;
    double angle_;
    Point center_;
};


void drawSquare(struct Square *) {
    std::cerr << "in drawSquare\n";
}

void drawCircle(struct Circle *) {
    std::cerr << "in drawCircle\n";
}

void drawRhomb(struct Rhomb*) {
    std::cerr <<"in drawRhomb\n";
}

void drawShapes(Shape **shapes, int n) {
    for (int i = 0; i < n; ++i) {
        struct Shape *s = shapes[i];
        switch (s->type_)  {
            case Shape::square:
                drawSquare((struct Square *)s);
                break;
            case Shape::circle:
                drawCircle((struct Circle *)s);
                break;
            case Shape::rhomb:
                drawRhomb((struct Rhomb*)s);
                break;
            default:
                assert(0);
                exit(0);
        }
    }
}


void moveSquare(struct Square* sq, double x, double y) {
    sq->center_.x += x;
    sq->center_.y += y;
    std::cerr <<"in moveSquare\n";
}
void moveCircle(struct Circle* c, double x, double y) {
    c->center_.x += x;
    c->center_.y += y;
    std::cerr <<"in moveCircle\n";
}
void moveRhomb(struct Rhomb* c, double x, double y) {
    c->center_.x += x;
    c->center_.y += y;
    std::cerr <<"in moveRhomb\n";
}

void moveShapes(Shape** shapes, int n, double x, double y) {
    for (int i = 0; i < n; ++i) {
        struct Shape* s = shapes[i];
        switch (s->type_) {
            case Shape::square:
                moveSquare((struct Square*)s, x, y);
                break;
            case Shape::circle:
                moveCircle((struct Circle*)s, x, y);
                break;
            case Shape::rhomb:
                moveRhomb((struct Rhomb*)s, x, y);
                break;
            default:
                assert(0);
                exit(0);
        }
    }
}

int main() {
    Shape *shapes[5];
    shapes[0] = (Shape *)new Circle;
    shapes[0]->type_ = Shape::circle;
    shapes[1] = (Shape *)new Square;
    shapes[1]->type_ = Shape::square;
    shapes[2] = (Shape *)new Square;
    shapes[2]->type_ = Shape::square;
    shapes[3] = (Shape *)new Circle;
    shapes[3]->type_ = Shape::circle;
    shapes[4]=(Shape*)new Rhomb;
    shapes[4]->type_=Shape::rhomb;

    drawShapes(shapes, 5);
    moveShapes(shapes, 5, 1, 1);
}