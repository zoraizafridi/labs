#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int findLHS(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int n : nums) freq[n]++;
    int longest = 0;
    for (auto& [num, count] : freq) {
        if (freq.find(num + 1) != freq.end()) {
            longest = max(longest, count + freq[num + 1]);
        }
    }
    return longest;
}
int main() {
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << "Longest Harmonious Subsequence Length: " << findLHS(nums) << "\n";
    return 0;
}
