#include <iostream>
#include "array_operations.h"
#include "file.h"

using namespace std;

int main() {
    cout << "Please Enter array size to initialize the program: ";
    int size;
    cin >> size;
    int arr[size]; //array declaration here because this is the common scope for other functions
    init(arr, size);
    cout << endl;

    //saving to file
    string fileName = "array.txt";
    fileExists(fileName);
    bool writeCheck = writeFile(arr, size, fileName);
    if (writeCheck) cout << "The sorted array is successfully saved to file " << fileName << endl;

    while (true) {
        cout << '\n';
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice : ";
        int choice;
        cin >> choice;
        if (choice == 5) break;
        else if (choice < 1 || choice > 5)cout << "Invalid Choice.Try again" << endl;
        else {
            switch (choice) {
                case 1:
                    insert(arr, size);
                    cout << "After insertion," << endl;
                    display(arr, size);
                    writeFile(arr, size, fileName);
                    cout << "File Updated" << endl;
                    break;
                case 2:
                    deleteItem(arr, size);
                    display(arr, size);
                    writeFile(arr, size, fileName);
                    cout << "File Updated" << endl;
                    break;
                case 3:
                    searchItem(arr, size);
                    break;
                case 4:
                    system("cls");
                    display(arr, size);
                    break;
                default:
                    break;

            }
        }
    }


    return 0;
}
