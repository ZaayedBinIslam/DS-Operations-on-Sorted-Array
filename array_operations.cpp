#include "array_operations.h"
#include "iostream"
#include <ctime>

void init(int arr[], int size) {
    std::cout << "The Randomly generated array is," << std::endl;
    srand(time(0));
    for (int i = 0; i < size; i++) {
        int num = rand() % 100;
        arr[i] = num;
        std::cout << num << '\t';
        if (i % 10 == 9) std::cout << std::endl;
    }
    std::cout << '\n';
    //bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
    //after sort
    std::cout << "After sorting the array becomes," << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << '\t';
        if (i % 10 == 9) std::cout << std::endl;
    }
    std::cout << '\n';

}

void insert(int arr[], int &size) {
    std::cout << "Enter the number to be inserted : ";
    int index, num;
    std::cin >> num;

    //if value found once or multiple times
    index = binary_search(num, arr, size);
    if (index > -1) {
        while (arr[index + 1] == num) index++; //finding last occurrence

        index++;// insert index set to the index after last occurrence

    } else { //if value not found
        for (int i = 0; i < size; i++) {
            //sets insertion index to the index of the first num
            //thats greater than the input number
            if (arr[i] > num) {
                index = i;
                break;
            }
            if (i == size - 1) index = size;
        }
    }
    //after we get the index,now we insert.
    for (int i = size - 1; i >= index; i--) { //change loc in reverse so no data is lost.
        arr[i + 1] = arr[i];                //n-1 till given index so that all data is properply moved
    }
    arr[index] = num;
    size++;

}

void deleteItem(int arr[], int &size) { //'delete' keyword reserved
    std::cout << "Enter the number to be deleted : ";
    int index, num;
    std::cin >> num;

    //if value found once or multiple times
    index = binary_search(num, arr, size);
    if (index > -1) {
        while (arr[index + 1] == num) index++; //finding last occurrence

        for (int i = index; i < size; i++) { //reverse of insertion
            arr[i] = arr[i + 1];
        }
        size--;
    } else { //if value not found
        std::cout << "Number Not Found." << std::endl;
    }

}

void searchItem(int arr[], int size) {
    std::cout << "Enter a number to search : ";
    int item;
    std::cin >> item;
    int index = binary_search(item, arr, size);
    if (index == -1) std::cout << "Not Found" << std::endl;
    else {
        std::cout << "First occurrence found at index " << index << " ." << std::endl;
    }


}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << "\t";
        if (i % 10 == 9) std::cout << std::endl;
    }
    std::cout << std::endl;
}

int binary_search(int item, int arr[], int size) {
    int index = -1;
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2; //type int so floor of float values are counted
        if (arr[mid] == item) { //if found ,set index and break
            index = mid;
            high = mid - 1; //this line ensures only first occurrence of a number is returned
        } else if (arr[mid] > item) {
            high = mid - 1;
        } else low = mid + 1;
    }
    return index;//returns -1 if not found
}