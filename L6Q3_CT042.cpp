#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

class Sort {
private:
    int comparisons;
    int swaps;
    void reset() {
        comparisons = 0;
        swaps = 0;
    }
public:
    Sort() { 
		reset();
	}
	struct Result {
            string name;
            int comps;
            int swaps;
    };
    void bubbleSort(vector<int>& arr) {
        reset();
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                comparisons++;
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swaps++;
                }
            }
        }
    }
	void selectionSort(vector<int>& arr) {
        reset();
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                comparisons++;
                if (arr[j] < arr[minIdx])
                    minIdx = j;
            }
            if (minIdx != i) {
                swap(arr[i], arr[minIdx]);
                swaps++;
            }
        }
    }
	void insertionSort(vector<int>& arr) {
        reset();
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                comparisons++;
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            }
            comparisons++; 
            arr[j + 1] = key;
        }
    }
    void sortArray(vector<int>& arr, string choice) {
        if (choice == "bubble")
            bubbleSort(arr);
        else if (choice == "selection")
            selectionSort(arr);
        else if (choice == "insertion")
            insertionSort(arr);
        else
            cout << "Invalid sorting choice!" << endl;
    }
	void analyze(vector<int> original) {
        vector<Result> results;
        
		vector<int> temp = original;
        bubbleSort(temp);
        results.push_back({"Bubble Sort", comparisons, swaps});
		
		temp = original;
        selectionSort(temp);
        results.push_back({"Selection Sort", comparisons, swaps});

        temp = original;
        insertionSort(temp);
        results.push_back({"Insertion Sort", comparisons, swaps});

        cout << "\n--- Sorting Analysis ---\n";
        for (const auto& r : results)
            cout << r.name << " => Comparisons: " << r.comps << ", Swaps: " << r.swaps << endl;
        // Determine best and worst
        int minOps = INT_MAX, maxOps = 0;
        string best, worst;
        for (const auto& r : results) {
            int totalOps = r.comps + r.swaps;
            if (totalOps < minOps) {
                minOps = totalOps;
                best = r.name;
            }
            if (totalOps > maxOps) {
                maxOps = totalOps;
                worst = r.name;
            }
        }

        cout << "\nBest Technique: " << best << endl;
        cout << "Worst Technique: " << worst << endl;
    }
};

int main() {
    Sort s;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    string choice;
    cout << "Enter sorting technique (bubble / selection / insertion): ";
    cin >> choice;

    vector<int> sortedArr = arr;
    s.sortArray(sortedArr, choice);

    cout << "\nSorted Array using " << choice << " sort: ";
    for (int x : sortedArr)
        cout << x << " ";
    
	cout << "\n";

    s.analyze(arr);
    return 0;
}
