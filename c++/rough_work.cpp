#include <iostream>
using namespace std;

// Function to calculate factorial of a number
long long int factorial(int num) {
    long long int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate permutations (nPr = n! / (n - r)!)
long long int permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Function to calculate combinations (nCr = n! / (r! * (n - r)!))
long long int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n, r;
    
    cout << "Enter the number of items (n): ";
    cin >> n;
    
    cout << "Enter the number of arrangements/selections (r): ";
    cin >> r;

    if (r > n) {
        cout << "r cannot be greater than n!" << endl;
        return 1;
    }
    
    // Calculate and display the factorial of n and r
    cout << "Factorial of n: " << factorial(n) << endl;
    cout << "Factorial of r: " << factorial(r) << endl;
    
    // Calculate and display permutation
    long long int perm = permutation(n, r);
    cout << "Permutation (nPr) = " << perm << endl;
    
    // Calculate and display combination
    long long int comb = combination(n, r);
    cout << "Combination (nCr) = " << comb << endl;

    return 0;
}
