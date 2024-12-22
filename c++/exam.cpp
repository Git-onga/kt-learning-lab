#include <iostream>
using namespace std;

// 1. code that accepts two numbers, swap them then display the swapped results

/*
class Values {
    private:
    int value1, value2;

    public:
    void acceptValues(int a ,int b){
        value1 = a;
        value2 = b;
    }

    void swapValues() {
        int temp = value1;
        value1 = value2;
        value2 = temp;
    }

    void displayValues()  const{
        cout <<"Value 1: "<<value1 <<endl;
        cout <<"Value 2: " <<value2 <<endl;
    }
};

int main() {
    Values obj;
    int a,b;

    cout << "Enter two Integer values: "<<endl;
    cin >>a >>b;

    obj.acceptValues(a,b);

    cout <<"\nBefore Swapping:" <<endl;
    obj.displayValues();

    obj.swapValues();

    cout <<"\nAfter Swapping: " <<endl;
    obj.displayValues();

    return 0;
}
*/

// 2. code for construct and distructors

    /*      ~~~~~~~~~~ NOTE ~~~~~~~~~
       - A constructor has the same name as the class.
       - A distructor is same as the constructor yet has '~'.
       - A constructor can have paramaters.    
       - Constructors are used for initialization while distructors used for cleanup.
    */
/*
class Example {
    public:

    //constructor
    Example(){
        cout <<"A consturctor is created" <<endl;
    }

    //distructor
    ~Example(){
        cout <<"Constructor is distroyed" <<endl;
    }
};

int main() {
    Example t;

    return 0;
}
*/


// 3. differentiate between Overridding and Overloadding 

/*
        ~~~~~~~~~~~~~~~ NOTE ~~~~~~~~~~~~~~
        - overloading a function occurs on the function in the same class while, Overriding a function occurs in a derived class relative to the base class.
        - Overlaoding functions have same name but different parameters while Overridding is basically redeclaring a base class method using same name and paramters.
*/
/*
class Example {
    public:
    void dispaly(int x){
        cout <<"Integer: " <<x <<endl;
    }

    void display(double x){
        cout <<"Double: "<<x <<endl;
    }

};

class Base{
    public:
    virtual void show(){
        cout <<"Base class show() function" <<endl;
    }

};

class Derived : public Base{
    public:
    void show() override {
        cout <<"Derived class show() Function";
    }
};

int main() {
    Example val1;

    val1.dispaly(56);
    val1.dispaly(69.43);

    Base o;

    o.show();

    Derived t;

    t.show();

    return 0;
}
*/

// 4. Single Inheritance
/*
class Square {
    public:
    int s, p;

    int area (int s) {
       int a = s * s;
       return a;
    }

    int parameter (int s) {
        int par = s * 4;
        return par;
    }

    void dispalyCalc() {
        cout <<"The Area of Square is " << area <<endl;
        cout <<"The Parameter of the Square is "<< parameter <<endl;
    }
};

class Rectangle: public Square {
    public:

    int area (int l, int w) {
        return l * w;
    }

    int parameter (int l, int w) {
        return (l + w) * 2;
    }

    void dispalyCalc() {
        cout <<"The Area of Rectangle is " << area <<endl;
        cout <<"The Parameter of the Rectangle is "<< parameter <<endl;
    }
  
};

int main() {
    Square p;
    p.area(5);
    p.parameter(5);
    p.dispalyCalc();

    Rectangle o;
    o.area(3,7);
    o.parameter(3,7);
    o.dispalyCalc();

    return 0;
}

*/

//4. class implemenation
/*
class cylinder {
    public:
    double pi;
    double height;
    double radius;
    int N;

    cylinder(double p, double h, double r, int N): pi(p), height(h), radius(r), N(N) {}

    ~cylinder() {
        cout <<"Constructor has been distroyed"<<endl;
    }

    double calVolume(){
        double volume = N * 1/3 * pi * height * radius * radius;
        return volume;
    };

};

int main (){
    cylinder cyl(3.14, 2.3, 4.3, 4);

    cout << "Volume is "<<cyl.calVolume() <<endl;
    return 0;   
    
}
*/
