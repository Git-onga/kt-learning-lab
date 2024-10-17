#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 9, b = 1;
    int *p, *q;
    p = &a;
    q = &b;
    swap(a,b);
    cout << "a " << *p <<" b " << *q <<endl;
    cout << "Cheers";
}