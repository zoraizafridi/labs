#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};
int sumNodes(Node* root) {
    if (!root) return 0;
    return root->val + sumNodes(root->left) + sumNodes(root->right);
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    cout << "Sum of all nodes: " << sumNodes(root) << endl;
}
