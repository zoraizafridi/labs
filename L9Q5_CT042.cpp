#include <iostream>
#include <climits>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};
void inOrder(Node* root, int& prev, int& minDiff) {
    if (!root) return;
    inOrder(root->left, prev, minDiff);
    if (prev != -1) minDiff = min(minDiff, root->val - prev);
    prev = root->val;
    inOrder(root->right, prev, minDiff);
}
int getMinimumDifference(Node* root) {
    int prev = -1;
    int minDiff = INT_MAX;
    inOrder(root, prev, minDiff);
    return minDiff;
}
int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    cout << "Minimum difference: " << getMinimumDifference(root) << endl;
}
