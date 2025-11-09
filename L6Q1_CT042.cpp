#include <iostream>
using namespace std;
bool isSorted(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void bubbleSort(int* arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int* arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 8, 6, 10, 2};
    int N = sizeof(arr) / sizeof(arr[0]);
    
    if (isSorted(arr, N)) {
        cout << "Array is already sorted." << endl;
    } else {
        bubbleSort(arr, N);
        cout << "Sorted array: " << endl;
    }
    printArray(arr, N);
    return 0;
}
