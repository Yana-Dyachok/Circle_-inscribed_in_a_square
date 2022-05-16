// Використовуючи поняття множинного успадкування, розробіть клас «Коло, вписане в квадрат».
#include <iostream>
#include <cmath>
using namespace std;
double pi = 3.14;//
class Circle {//клас Коло
protected:
    int radius;//радіус кола
public:
    Circle(int radius) {
        this->radius = radius;
    }
    double getLength() {//метод знаходження довжини кола
        return 2 * pi * radius;
   }

    double getAreaC() {//метод знаходження площі кола
        return pi * pow(radius, 2);
    }


    ~Circle() {}
};


class Square {//клас Квадрат
protected:
    int side;
public:
    Square(int side) {
        this->side = side;
    }


    double getAreaS() {//метод знаходження площі квадрата
        return pow(side, 2);
    }


    double getPerimetr() {//метод знаходження периметра квадрата
        return 4*side;
    }


    ~Square() {}
};


class CircleInSquare:public Circle, public Square {//клас «Коло, вписане в квадрат».
protected:
    int diametr;//діаметр кола
public:
    CircleInSquare(int diametr) : Circle(radius * 2), Square(side) {
        this->diametr = diametr;
        radius = this->diametr / 2;
        side= this->diametr;
    }


    ~CircleInSquare(){}
};


int main()
{ 
    CircleInSquare A(8);//об'єкт класу CircleInSquare
   cout<<"Area of the square= " << A.getAreaS()<< endl;
   cout<<"Area of the circle= " << A.getAreaC()<< endl;
   cout << "Length of the circle= " << A.getLength() << endl;
   cout << "Perimetr of the square= " << A.getPerimetr() << endl;
}
