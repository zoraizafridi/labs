#include <iostream>
#include <algorithm>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};
class Solution {
    pair<int, int> robHelper(Node* root) {
        if (!root) return {0, 0}; // {rob, notRob}

        auto left = robHelper(root->left);
        auto right = robHelper(root->right);

        int rob = root->val + left.second + right.second;
        int notRob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, notRob};
    }
public:
    int rob(Node* root) {
        auto res = robHelper(root);
        return max(res.first, res.second);
    }
};
int main() {
    Node* root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(3);
    root->right->right = new Node(1);

    Solution s;
    cout << "Max money: " << s.rob(root) << endl;
}
