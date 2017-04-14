#include <iostream>
#include <list>


struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};


/* shapes */

class Shape {
    public:
        virtual void draw() = 0;
        virtual void move(int x, int y) = 0;
};

class Circle : public Shape {
    private:
        double radius_;
        Point center_;
    public:
        Circle() : center_(Point(0,0)) {}
        virtual void draw();
        virtual void move(int x, int y);
};

class Square : public Shape {
    private:
        double side_;
        Point center_;
    public:
        Square() : center_(Point(0,0)) {}
        virtual void draw();
        virtual void move(int x, int y);
};

class Rhomb : public Shape {
    private:
        double side_;
        double angle_;
        Point center_;
    public:
        Rhomb() : center_(Point(0,0)) {}
        virtual void draw();
        virtual void move(int x, int y);
};


/* draw */

void Circle::draw() {
    std::cerr << "in drawCircle\n";
}

void Square::draw() {
    std::cerr << "in drawSquare\n";
}

void Rhomb::draw() {
    std::cerr << "in drawRhomb\n";
}

void drawShapes(std::list<Shape*>& shapes) {
    for (auto it = shapes.cbegin(); it != shapes.cend(); it++) {
        (*it)->draw();
    }
}


/* move */

void Circle::move(int x, int y) {
    this->center_.x += x;
    this->center_.y += y;
    std::cerr <<"in moveCircle\n";
}

void Square::move(int x, int y) {
    this->center_.x += x;
    this->center_.y += y;
    std::cerr <<"in moveSquare\n";
}

void Rhomb::move(int x, int y) {
    this->center_.x += x;
    this->center_.y += y;
    std::cerr <<"in moveRhomb\n";
    // std::cout << this->center_.x << " " << this->center_.y << std::endl;
}

void moveShapes(std::list<Shape*>& shapes, int x, int y) {
    for (auto it = shapes.cbegin(); it != shapes.cend(); it++) {
        (*it)->move(x, y);
    }
}


/* main */

int main() {
    std::list<Shape*> shapes;
    shapes.push_back(new Circle());
    shapes.push_back(new Square());
    shapes.push_back(new Rhomb());

    drawShapes(shapes);
    moveShapes(shapes, 1, 1);
}

// g++ -std=c++11 solution.cpp - o solution