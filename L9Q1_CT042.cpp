#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Example01 {
public:
    // Preorder traversal using stack
    void preorder(Node* root) {
        if (!root) return;
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* curr = st.top(); st.pop();
            cout << curr->val << " ";

            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);
        }
    }
    // Postorder traversal using two stacks
    void postorder(Node* root) {
        if (!root) return;
        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* curr = s1.top(); s1.pop();
            s2.push(curr);
            if (curr->left) s1.push(curr->left);
            if (curr->right) s1.push(curr->right);
        }
        while (!s2.empty()) {
            cout << s2.top()->val << " ";
            s2.pop();
        }
    }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Example01 ex;
    cout << "Preorder: "; ex.preorder(root); cout << endl;
    cout << "Postorder: "; ex.postorder(root); cout << endl;
}
