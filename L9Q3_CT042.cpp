#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};
// LCA in BST
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (!root) return nullptr;
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    return root;
}
int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    Node* lca = lowestCommonAncestor(root, root->left->left, root->left->right);
    cout << "LCA: " << lca->val << endl;
}