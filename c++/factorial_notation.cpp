#include <iostream>
#include <algorithm> // Required for sort and next_permutation
#include <string>  
#include <iomanip> //for controlling column width
#include <vector> //for storeing permutations   
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
    string word, originalWord;
    int columns = 3;
    char choice;
    int permIndex = 0;
    long long int n, r;

    cout << "WELCOME TO PERMUTATION AND COMBUNATION PROGRAM" <<endl;
    cout << "Choose the Format of your Input" <<endl;
    cout << "1. NUMBERS"<<endl <<"2.WORDS" <<endl;
    cin >> choice;

    

    if(choice == '1') {   
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
    } else if(choice == '2'){
        cout << "Enter your Word: ";
        cin >> word;

        //store the original word
        originalWord = word;

        // sort the word in lexicographical order
        sort(word.begin(), word.end());

        //storing permutation in vector
        vector<string> permutations;

        //generate the posible permutation
        do{
            permutations.push_back(word);
        } while(next_permutation(word.begin(), word.end()));

        //caculate the number of permutattions 
        int totalPremutations = permutations.size();

        int tRow = (totalPremutations / 3);

        for (int row = 0; row < tRow; row++) {
            // Print the top border of each row
            cout << "-----------------------------------------------------------------------------\n";
            
            // Print the contents of the row
            cout << "|        "<< permutations[permIndex++]<<"         |          "<< permutations[permIndex++]<<"            |          "<< permutations[permIndex++]<<"      |\n";
            
            // Print the bottom border
            cout << "-----------------------------------------------------------------------------\n";
        }

        // display permutation
        cout<< "The total Permuation of "<< originalWord <<" is "<< totalPremutations;
    
    } else {
        cout << "Invalid input" ;
    }

    
    return 0;
}