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
class Tree {
public:
    int checkHeight(Node* root) {
        if (!root) return 0;

        int leftH = checkHeight(root->left);
        if (leftH == -1) return -1; // left unbalanced

        int rightH = checkHeight(root->right);
        if (rightH == -1) return -1; // right unbalanced

        if (abs(leftH - rightH) > 1) return -1; // current node unbalanced

        return max(leftH, rightH) + 1; // return height
    }
    bool isBalanced(Node* root) {
        return checkHeight(root) != -1;
    }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    Tree t;
    cout << (t.isBalanced(root) ? "Balanced" : "Not Balanced") << endl;
}
