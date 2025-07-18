/*
NUR ADWA NAYLI BINTI ZULKAINI
22011769

lab 7
TREE
*/

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(string n) : name(n) {}
};

class Tree {
public:
    Node* root = nullptr;

    void add_root(const string& name) {
        root = new Node(name);
    }

    void add_left(Node* parent, const string& name) {
        if (parent) parent->left = new Node(name);
    }

    void add_right(Node* parent, const string& name) {
        if (parent) parent->right = new Node(name);
    }

    void display_tree() const {
        if (!root) return;
        cout << "Root: " << root->name << endl;
        cout << "Left child of root: " << root->left->name << endl;
        cout << "Right child of root: " << root->right->name << endl;
        cout << "Left child of " << root->left->name << ": " << root->left->left->name << endl;
        cout << "Right child of " << root->left->name << ": " << root->left->right->name << endl;
        cout << "Left child of " << root->right->name << ": " << root->right->left->name << endl;
        cout << "Right child of " << root->right->name << ": " << root->right->right->name << endl;
    }
};

int main() {
    Tree tree;

    tree.add_root("A");
    tree.add_left(tree.root, "B");
    tree.add_right(tree.root, "C");
    tree.add_left(tree.root->left, "D");
    tree.add_right(tree.root->left, "E");
    tree.add_left(tree.root->right, "F");
    tree.add_right(tree.root->right, "G");

    tree.display_tree();

    return 0;
}