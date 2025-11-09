#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pancakeflip(vector<int>& arr,int n){
	vector<int> flips;
	for(int i=n;i>0;i--){
		int maxindex=0;
		for(int j=0;j<i;j++){
			if(arr[j]>arr[maxindex]){
				maxindex=j;
			}
		}
		if(maxindex != i-1){
			if(maxindex != 0){
				reverse(arr.begin(),arr.begin()+ maxindex+1);
				flips.push_back(maxindex+1);
			}
			reverse(arr.begin(),arr.begin()+i);
			flips.push_back(i);
		}
	}
	return flips;
}
int main() {
    vector<int> arr = {3, 2, 4, 1};
    vector<int> flips = pancakeflip(arr, arr.size());

    cout << "Flip sequence (k values): ";
    for (int k : flips)
        cout << k << " ";
    cout << endl;

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}