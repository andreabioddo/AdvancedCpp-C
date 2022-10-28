/**
 * @file Ex1Over.cpp
 * @author Andrea Bioddo (anbioddo@edu.aau.at)
 * @version 0.1
 * @date 2022-10-28
 * @brief Classes without virtual method to see the differences between virtual methods and ovverride methods
 * 
 */

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Class used to rapresent shapes with an height and a width
 * 
 */
class Shape{
    protected:
        int width, height;

    public:
        /*Constructor of the class*/
        Shape(int a=0, int b=0){
            width = a;
            height = b;
        }

        void display(){
            cout << "Shape" << endl;
        }

        int area(){
            cout << "Parent class area: " << endl;
            return 0;
        }
};

/**
 * @brief Class used to rapresent a polygon with n. angles. 
 * 
 */
class AngleShape:public Shape {
    protected:
        int angleNum;
    
    public:
        /*Constructor of the class*/
        AngleShape(int ang=0, int a=0, int b=0):Shape(a,b){
            ang=angleNum;
        }
        
        int getNumAngle(){
            return angleNum;
        }

        void display(){
            cout << "AngleShape" << endl;
        }

        int area() {
            return 0;
        }
};

/**
 * @brief Class used to rapresent shapes with no angles
 * 
 */
class CurvedShape:public Shape {        
    public:
        /*Constructor of the class*/
        CurvedShape(int a=0, int b=0):Shape(a,b){}

        void display(){
            cout << "Curved shape" << endl;
        }

        int area(){
            return 0;
        }
};

/**
 * @brief Class used to rapresent rectangles
 * 
 */
class Rectangle: public AngleShape {
    public: 
        /*Constructor of the class*/
        Rectangle(int a=0, int b=0):AngleShape(4,a,b){ }

        void display(){
            cout << "Rectangle class area: " << area() << endl;
        }

        int area() {
            return (width*height);
        }
};

/**
 * @brief Class used to rapresent Triangles
 * 
 */
class Triangle: public AngleShape{
    public:
        /*Constructor of the class*/
        Triangle(int a=0, int b=0):AngleShape(3, a,b){ }

        void display(){
            cout << "Triangle class area: " << area() << endl;
        }
        int area(){
            return (width*height/2);
        }
};

/**
 * @brief Class used to rapresent Trapezoids
 * 
 */
class Trapezoid:public AngleShape{
    protected:
        /*Added an attribute to rapresent the minor base*/
        int minorBase;
    public:
        /*Constructor of the class*/
        Trapezoid(int height, int majBase, int minBase):AngleShape(4, majBase, height){
            minorBase = minBase;
        }

        int area(){
            return (width+minorBase)/2*height;
        }

        void display(){
            cout << "Trapezoid class with area: " << area() << endl;
        }
};

/**
 * @brief Class used to rapresent Circle
 * 
 */
class Circle:public CurvedShape{
    public:
        /*Constructor of the class*/
        Circle(int a=0): CurvedShape(a,a){}
        
        void display(){
            cout << "Circle class with area " << area() << endl;
        }

        int area(){
            return width*height*M_PI;
        }
};

/**
 * @brief Class used to rapresent Elipse
 * 
 */
class Elipse: public CurvedShape{
    public:
        /*Constructor of the class*/
        Elipse(int a=0, int b=0):CurvedShape(a,b){}

        void display(){
            cout << "Elipse class with area: " << area() << endl;
        }

        int area(){
            return width*height*M_PI;
        }
};

int main(){
    Shape *shape;
    AngleShape *angleSh;
    CurvedShape *curvedSh;
    Rectangle rect(10,20);
    Triangle triang(10,20);
    Trapezoid trap(20,10,10);
    Circle circle(10);
    Elipse elipse(10,20);

    /*Using AngleShape*/
    cout << "Using AngleShape" << endl;

    angleSh = &rect;
    angleSh->display();

    angleSh = &triang;
    angleSh->display();

    angleSh = &trap;
    angleSh->display();

    /*Using AngleShape*/
    cout << "\nUsing CurvedShape" << endl;

    curvedSh = &circle;
    curvedSh->display();

    curvedSh = &elipse;
    curvedSh->display();

    /*Using Shape*/
    cout << "\nUsing Shape" << endl;
    
    shape = &rect;
    shape->display();

    shape = &triang;
    shape->display();

    shape = &trap;
    shape->display();

    shape = &circle;
    shape->display();

    shape = &elipse;
    shape->display();
}