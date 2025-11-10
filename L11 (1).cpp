#include <iostream>
using namespace std;

void heapifyDown(int arr[], int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyDown(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    if (n <= 1) return;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyDown(arr, n, i);
    swap(arr[0], arr[n - 1]);
    heapifyDown(arr, n - 1, 0);
    heapSort(arr, n - 1);
}

int main() {
    int arr[] = {100, 50, 80, 30, 70, 65,55,20,40,60,90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    heapSort(arr, n);

    cout << "Sorted Max: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
