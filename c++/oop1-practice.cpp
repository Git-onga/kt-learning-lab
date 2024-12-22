#include <iostream>
#include <string>
using namespace std;

class car {
    //members of the class car
    public:
        string color;
        string model;
        int yearOfMake;
        int finalDistance;
        int startDisatnce;
        int finalTime;
        int startTime;

    //constructor 
    car(string c, string m, int y, int fd, int sd, int ft, int st): color(c), model(m), yearOfMake(y), finalDistance(fd), startDisatnce(sd), finalTime(ft), startTime(st) {}

    //destroctor
    ~car() {
        cout <<"class has been deleted" <<endl;
    };


    // method of calculating the speed and acceleraion
    int speed(){
        int totalSpeed = (finalDistance - startDisatnce) / (finalTime - startTime);
        return totalSpeed;
    }

    int acceleration(){
        int velocity = ((finalDistance - startDisatnce) / (finalTime - startTime));
        double totalAcc = (velocity / (finalTime - startTime));
        return totalAcc;
    }

    friend void remark (int startTime, int finalTime);

};

void remark(int startTime, int finalTime){
    int time = finalTime - startTime;
    if (time < 1){
        cout <<"Fast Acceleration!!" <<endl;
    } else if( time < 5){
        cout <<"Medium Acceleration" <<endl;
    } else {
        cout <<"Slow Acceleration" <<endl;
    }
}

int main(){

    //using a contructor to set the vavules of an object
    car x("blue", "Toyota MarkX", 2019, 400, 200, 2, 0);
    car y("Grey", "Audi C200", 2021, 800, 500, 7, 6);


    cout <<endl;

    /*          
    
    ~~ has been replaced with a constructor ~~

    x.color = "Blue";
    x.model = "Toyota MarkX";
    x.yearOfMake = 2019;
    x.finalDistance = 400;
    x.startDisatnce = 200;
    x.finalTime = 2;
    x.startTime = 0;

    y.color = "Grey";
    y.model = "Audi C200";
    y.yearOfMake = 2021;
    y.finalDistance = 800;
    y.startDisatnce = 500;
    y.finalTime = 7;
    y.startTime = 6;
    */


    cout << "car x color " <<x.color <<endl;
    cout << "car x model " <<x.model <<endl;
    cout << "car x year of make " <<x.yearOfMake <<endl;
    cout << "car x can cover a speed of "<<x.speed() <<" km/h with an acceleration of " <<x.acceleration() <<"m/s";
    remark(x.startTime, x.finalTime);

    cout <<endl << "car y color " <<y.color <<endl;
    cout << "car y model " <<y.model <<endl;
    cout << "car y year of make " <<y.yearOfMake <<endl;
    cout << "car y can cover a speed of "<<y.speed() <<" with an acceleration of " <<y.acceleration() <<endl;
    remark(y.startTime, y.finalTime);

    return 0;
}