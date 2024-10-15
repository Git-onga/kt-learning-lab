#include <iostream>
using namespace std;

// Function to traverse the array
void traverseArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to search for an element in the array
int searchElement(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // Return the index if the element is found
        }
    }
    return -1;  // Return -1 if the element is not found
}

// Function to insert an element into the array
int insertElement(int arr[], int size, int capacity, int element, int pos) {
    if (size >= capacity) {
        cout << "Array is full. Cannot insert element." << endl;
        return size;
    }

    if (pos < 0 || pos > size) {
        cout << "Invalid position." << endl;
        return size;
    }
    

    // Shift elements to the right
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = element;
    return size + 1;

}

// Function to delete an element from the array
int deleteElement(int arr[], int size, int pos) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position." << endl;
        return size;
    }

    // Shift elements to the left
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

// Function to update an element in the array
void updateElement(int arr[], int size, int pos, int newElement) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position." << endl;
        return;
    }
    arr[pos] = newElement;
}

void bubbleSort(int arr[], int size) {
    for( int i = 0; i < size-1; i++){
        for(int j=0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    traverseArray(arr, size);
}

int main() {
    const int capacity = 100;  // Maximum capacity of the array
    int arr[capacity] = {}; // Initialize the array
    int size , choice, pos, element;  // Current size of the array


   cout << "Enter the size of your array: ";
   cin >> size;
    
    for(int i=0; i < size; i++){
        cout << "Enter your ARRAY: ";
        cin >> arr[i];
    }

    cout <<endl;
    cout << "1: Traverse\n2: Search\n3: Insert\n4: Delete\n5: Update\n6: Bubble sort\n" <<endl;

    cout << "Chose the operation for the Array: ";
    cin >> choice;

    
    if (choice == 1)
    {
        traverseArray(arr, size);
    } else if(choice == 2) {
        int key;
        cout <<"Enter the element to search for: ";
        cin >> key;
        int index = searchElement(arr, size, key);
        if (index != -1) {
            cout << "Element found at index: " << index << endl;
        } else {
            cout << "Element not found." << endl;
        }
    } else if (choice == 3) {
        cout << "Enter the Element: ";
        cin >> element;
        cout << "Enter the Position: ";
        cin >> pos;
        size = insertElement(arr,size,capacity,element,pos);
        traverseArray(arr,size);
    } else if (choice == 4){
        cout << "Enter the Position to delete: ";
        cin >> pos;
        size = deleteElement(arr, size, pos);
        traverseArray(arr, size);
    } else if(choice == 5){
        int newElement;
        cout << "Enter the New element to update: ";
        cin >> newElement;
        cout << "Enter the position for the new element: ";
        cin >> pos;
        updateElement(arr,size,pos,newElement);
        traverseArray(arr,size);
    } else if(choice == 6){
        bubbleSort(arr, size);
    }else {
        cout << "Invalid Operation";
    }

    
    return 0;
}


    /*
    // Traverse the array
    traverseArray(arr, size);

    // Search for an element
    int key = 30;
    int index = searchElement(arr, size, key);
    if (index != -1) {
        cout << "Element " << key << " found at index " << index << endl;
    } else {
        cout << "Element " << key << " not found" << endl;
    }

    // Insert an element
    int elementToInsert = 25;
    int positionToInsert = 2;
    size = insertElement(arr, size, capacity, elementToInsert, positionToInsert);
    cout << "After insertion:" << endl;
    traverseArray(arr, size);

    // Delete an element
    int positionToDelete = 3;
    size = deleteElement(arr, size, positionToDelete);
    cout << "After deletion:" << endl;
    traverseArray(arr, size);

    // Update an element
    int positionToUpdate = 1;
    int newElement = 15;
    updateElement(arr, size, positionToUpdate, newElement);
    cout << "After updating:" << endl;
    traverseArray(arr, size);



    updated code 


    #include <iostream>
using namespace std;

// Function to traverse the array
void traverseArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to search for an element in the array
int searchElement(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // Return the index if the element is found
        }
    }
    return -1;  // Return -1 if the element is not found
}

// Function to insert an element into the array
int insertElement(int arr[], int size, int capacity, int element, int pos) {
    if (size >= capacity) {
        cout << "Array is full. Cannot insert element." << endl;
        return size;
    }

    if (pos < 0 || pos > size) {
        cout << "Invalid position." << endl;
        return size;
    }

    // Shift elements to the right
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = element;
    return size + 1;
}

// Function to delete an element from the array
int deleteElement(int arr[], int size, int pos) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position." << endl;
        return size;
    }

    // Shift elements to the left
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

// Function to update an element in the array
void updateElement(int arr[], int size, int pos, int newElement) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position." << endl;
        return;
    }
    arr[pos] = newElement;
}

int main() {
    const int capacity = 100;  // Maximum capacity of the array
    int arr[capacity] = {}; // Initialize the array
    int size, choice, pos, element;  // Current size of the array

    cout << "Enter the size of your array: ";
    cin >> size;
    
    for(int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << endl;
    cout << "1: Traverse\n2: Search\n3: Insert\n4: Delete\n5: Update\n" << endl;

    cout << "Choose the operation for the Array: ";
    cin >> choice;

    if (choice == 1) {
        traverseArray(arr, size);
    } else if (choice == 2) {
        int key;
        cout << "Enter the element to search for: ";
        cin >> key;
        int index = searchElement(arr, size, key);
        if (index != -1) {
            cout << "Element found at index: " << index << endl;
        } else {
            cout << "Element not found." << endl;
        }
    } else if (choice == 3) {
        cout << "Enter the Element: ";
        cin >> element;
        cout << "Enter the Position: ";
        cin >> pos;
        size = insertElement(arr, size, capacity, element, pos);
        traverseArray(arr, size); // Display the array after insertion
    } else if (choice == 4) {
        cout << "Enter the Position to delete: ";
        cin >> pos;
        size = deleteElement(arr, size, pos);
        traverseArray(arr, size); // Display the array after deletion
    } else if (choice == 5) {
        int newElement;
        cout << "Enter the New element to update: ";
        cin >> newElement;
        cout << "Enter the position for the new element: ";
        cin >> pos;
        updateElement(arr, size, pos, newElement);
        traverseArray(arr, size); // Display the array after update
    } else {
        cout << "Invalid Operation" << endl;
    }

    return 0;
}

    */