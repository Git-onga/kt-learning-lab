#include <iostream>
using namespace std;

//inverter gate function
int nOT(int input){
    if (input == 1){
        return 0;
    } else if (input == 0){
        return 1;
    } else{
        return -1;
    }
}

// The AND gate function
int aND(int a, int b){
    if (a == 1 && b == 1){
        return 1;
    } else {
        return 0;
    }
}

// The NOT gate function
int oR( int a, int b){
    if (a == 0 && b == 0){
        return 0;
    } else {
        return 1;
    }
}

//The unversal gate NAND
int nAND(int a, int b){
    if(a == 1 && b == 1){
        return 0;
    } else {
        return 1;
    }
    
}

// The universal gate NOR
int nOR(int a, int b){
    if(a == 0 && b == 0){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int input, output;
    char choice;

    cout << "Welcome to Logic Gates Program" <<endl; 
    cout << "Choose the gate to work with " << endl;
    cout << "------------------------------" << endl;
    cout << "1.NOT" << endl << "2.AND" << endl <<"3.OR" <<endl << "4.NAND" <<endl << "5.NOR" <<endl;
    cin >> choice;

    
    if (choice == '1'){
        //NOT GATE 
        
        //addd constraints so as to ensure only binary digits
        do{
            cout << "Enter the Input :" <<endl;
            cin >> input;
        } while(input != 0 || input != 1);
        
        output = nOT(input);
        cout << "The output is " <<output;

    } else if(choice == '2'){
        //AND GATE
        int a,b;

        //addd constraints so as to ensure only binary digits

        do {
            cout << "Enter the Inputs: " <<endl << "A ";
            cin >> a; 

            if (a != 0 && a != 1) {
                cout << "Invalid Option. Enter 0 or 1" <<endl;
            }

        } while(a != 0 && a!=1);
        do{
            cout << "B ";   
            cin >> b;

            if (b != 0 && b != 1) {
                cout << "Invalid Option. Enter 0 or 1" <<endl;
            }

        } while(b != 0 && b != 1);

        cout <<"Value of A " <<a <<endl;
        cout <<"value of B " <<b <<endl;
        
        output = aND(a,b);
        cout << "The output is " <<output;
    } else if (choice = '3'){

        //NOT GATE
        int a,b;

        //addd constraints so as to ensure only binary digits

        do {
            cout << "Enter the Inputs: " <<endl << "A ";
            cin >> a; 

            if (a != 0 && a != 1) {
                cout << "Invalid Option. Enter 0 or 1" <<endl;
            }

        } while(a != 0 && a!=1);

        do{
            cout << "B ";   
            cin >> b;

            if (b != 0 && b != 1) {
                cout << "Invalid Option. Enter 0 or 1" <<endl;
            }

        } while(b != 0 && b != 1);

        cout <<"Value of A " <<a <<endl;
        cout <<"value of B " <<b <<endl;
        
        output = oR(a,b);
        cout << "The output is " <<output;
    } else if (choice == '4'){
    //NAND GATE
        int a,b;

        //addd constraints so as to ensure only binary digits

        do {
            cout << "Enter the Inputs: " <<endl << "A ";
            cin >> a; 

            if (a != 0 && a != 1) {
                cout << "Invalid Option. Enter 0 or 1" <<endl;
            }

        } while(a != 0 && a!=1);

        do{
            cout << "B ";   
            cin >> b;

            if (b != 0 && b != 1) {
                cout << "Invalid Option. Enter 0 or 1" <<endl;
            }

        } while(b != 0 && b != 1);

        cout <<"Value of A " <<a <<endl;
        cout <<"value of B " <<b <<endl;
        
        output = nAND(a,b);
        cout << "The output is " <<output;
    } else if (choice == '5'){
        //NOR GATE
        int a,b;

        //addd constraints so as to ensure only binary digits

        do {
            cout << "Enter the Inputs: " <<endl << "A ";
            cin >> a; 

            if (a != 0 && a != 1) {
                cout << "Invalid Option. Enter 0 or 1" <<endl;
            }

        } while(a != 0 && a!=1);

        do{
            cout << "B ";   
            cin >> b;

            if (b != 0 && b != 1) {
                cout << "Invalid Option. Enter 0 or 1" <<endl;
            }

        } while(b != 0 && b != 1);

        cout <<"Value of A " <<a <<endl;
        cout <<"value of B " <<b <<endl;
        
        output = nOR(a,b);
        cout << "The output is " <<output;
    }
    

    
    return 0;
}
