#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (int n : nums) {
        if (n == 0) count0++;
        else if (n == 1) count1++;
        else count2++;
    }
    int index = 0;
    while (count0--) 
		nums[index++] = 0;
    while (count1--) 
		nums[index++] = 1;
    while (count2--) 
		nums[index++] = 2;
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);

    cout << "Sorted array: ";
    for (int n : nums) 
		cout << n << " ";
    cout << endl;
    return 0;
}
