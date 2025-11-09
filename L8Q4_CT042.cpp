#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};
class TreeBuilder {
    unordered_map<int, int> inorderMap;
    int preIndex = 0;
public:
    Node* build(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if (start > end) return nullptr;

        Node* root = new Node(preorder[preIndex++]);
        int idx = inorderMap[root->val];

        root->left = build(preorder, inorder, start, idx - 1);
        root->right = build(preorder, inorder, idx + 1, end);

        return root;
    }
    Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorderMap.clear();
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        preIndex = 0;
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
    void printInorder(Node* root) {
        if (!root) return;
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
};
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeBuilder tb;
    Node* root = tb.buildTree(preorder, inorder);

    tb.printInorder(root);
}
