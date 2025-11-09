#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
    void preorderTraversal(Node* root) {
        if (!root) return;
        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    void postorderTraversal(Node* root) {
        if (!root) return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->val << " ";
    }
    bool search(Node* root, int target) {
        if (!root) return false;
        if (root->val == target) return true;
        return search(root->left, target) || search(root->right, target);
    }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder: ";
    root->preorderTraversal(root);
    cout << "\nPostorder: ";
    root->postorderTraversal(root);

    cout << "\nSearch 5: " << (root->search(root, 5) ? "Found" : "Not Found") << endl;
    cout << "Search 9: " << (root->search(root, 9) ? "Found" : "Not Found") << endl;
}
