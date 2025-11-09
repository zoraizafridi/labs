#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSortIterative(vector<int>& arr, int low, int high) {
    stack<pair<int, int>> st;
    st.push({low, high});
    while (!st.empty()) {
        auto range = st.top();
        st.pop();
        int l = range.first;
        int h = range.second;
        if (l < h) {
            int p = partition(arr, l, h);
            // Push right then left (LIFO ? left gets processed next)
            st.push({p + 1, h});
            st.push({l, p - 1});
        }
    }
}
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
    quickSortIterative(arr, 0, arr.size() - 1);
    cout << "Sorted array (Iterative QuickSort): ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
