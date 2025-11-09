#include <iostream>
#include <string>
using namespace std;

class EmployeeNode {
public:
    int id;
    string name;
    string department;
    EmployeeNode* left;
    EmployeeNode* right;
    EmployeeNode(int i, string n, string d)
        : id(i), name(n), department(d), left(nullptr), right(nullptr) {}
};
class EmployeeBST {
private:
    EmployeeNode* root;
    EmployeeNode* insertNode(EmployeeNode* node, int id, string name, string department) {
        if (!node) return new EmployeeNode(id, name, department);

        if (id < node->id)
            node->left = insertNode(node->left, id, name, department);
        else if (id > node->id)
            node->right = insertNode(node->right, id, name, department);
        else
            cout << "Duplicate ID " << id << " not allowed." << endl;

        return node;
    }
    EmployeeNode* searchNode(EmployeeNode* node, int id) {
        if (!node || node->id == id) return node;
        if (id < node->id) return searchNode(node->left, id);
        return searchNode(node->right, id);
    }
    EmployeeNode* findMinNode(EmployeeNode* node) {
        while (node && node->left) node = node->left;
        return node;
    }
    EmployeeNode* deleteNodeHelper(EmployeeNode* node, int id) {
        if (!node) {
            cout << "ID " << id << " not found." << endl;
            return nullptr;
        }
        if (id < node->id)
            node->left = deleteNodeHelper(node->left, id);
        else if (id > node->id)
            node->right = deleteNodeHelper(node->right, id);
        else {
            // Node found
            if (!node->left) {
                EmployeeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                EmployeeNode* temp = node->left;
                delete node;
                return temp;
            }
            else {
                EmployeeNode* temp = findMinNode(node->right);
                node->id = temp->id;
                node->name = temp->name;
                node->department = temp->department;
                node->right = deleteNodeHelper(node->right, temp->id);
            }
        }
        return node;
    }
    void inOrderHelper(EmployeeNode* node) {
        if (!node) return;
        inOrderHelper(node->left);
        cout << node->id << " " << node->name << " " << node->department << endl;
        inOrderHelper(node->right);
    }

public:
    EmployeeBST() : root(nullptr) {}

    void insert(int id, string name, string department) {
        root = insertNode(root, id, name, department);
    }
    void search(int id) {
        EmployeeNode* node = searchNode(root, id);
        if (node)
            cout << "Found: " << node->name << ", " << node->department << endl;
        else
            cout << "ID " << id << " not found." << endl;
    }
    void deleteNode(int id) {
        root = deleteNodeHelper(root, id);
    }
    void inOrderTraversal() {
        inOrderHelper(root);
    }
    void findMin() {
        EmployeeNode* node = findMinNode(root);
        if (node) cout << "Min ID: " << node->id << ", " << node->name << ", " << node->department << endl;
    }
    void findMax() {
        EmployeeNode* node = root;
        if (!node) return;
        while (node->right) node = node->right;
        cout << "Max ID: " << node->id << ", " << node->name << ", " << node->department << endl;
    }
};
int main() {
    EmployeeBST bst;
    bst.insert(101, "Alice", "HR");
    bst.insert(50, "Bob", "IT");
    bst.insert(150, "Charlie", "Finance");
    bst.insert(120, "David", "IT");
    bst.insert(180, "Eva", "HR");

    cout << "InOrder Traversal:\n"; bst.inOrderTraversal();

    bst.search(120);
    bst.deleteNode(150);
    bst.findMin();
    bst.findMax();
}