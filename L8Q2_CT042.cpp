#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
    bool isMirror(Node* a, Node* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return (a->val == b->val) &&
               isMirror(a->left, b->right) &&
               isMirror(a->right, b->left);
    }
    bool isSymmetric(Node* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
    cout << (root->isSymmetric(root) ? "Tree is symmetric" : "Tree is not symmetric") << endl;
}