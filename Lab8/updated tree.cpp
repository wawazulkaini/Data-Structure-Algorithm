/*
NUR ADWA NAYLI BINTI ZULKAINI
22011769

lab 8
TREE updated w seacrh method
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int val) : data(val) {}
};

class Tree {
public:
    Node* root = nullptr;

    void add_root(int val) {
        root = new Node(val);
    }

    void add_left(Node* parent, int val) {
        if (parent) parent->left = new Node(val);
    }

    void add_right(Node* parent, int val) {
        if (parent) parent->right = new Node(val);
    }

    void display_tree() const {
        if (!root) return;
        cout << "Root: " << root->data << endl;
        cout << "Left child of root: " << root->left->data << endl;
        cout << "Right child of root: " << root->right->data << endl;
        cout << "Left child of " << root->left->data << ": " << root->left->left->data << endl;
        cout << "Right child of " << root->left->data << ": " << root->left->right->data << endl;
        cout << "Left child of " << root->right->data << ": " << root->right->left->data << endl;
        cout << "Right child of " << root->right->data << ": " << root->right->right->data << endl;
    }

    Node* search(int target) {
        return search_helper(root, target);
    }

private:
    Node* search_helper(Node* current, int target) {
        if (current == nullptr) return nullptr;

        if (current->data == target)
            return current;

        Node* left_result = search_helper(current->left, target);
        if (left_result) return left_result;

        return search_helper(current->right, target);
    }
};
int main() {
    Tree tree;

    tree.add_root(1);
    tree.add_left(tree.root, 2);
    tree.add_right(tree.root, 3);
    tree.add_left(tree.root->left, 4);
    tree.add_right(tree.root->left, 5);
    tree.add_left(tree.root->right, 6);
    tree.add_right(tree.root->right, 7);

    tree.display_tree();

    int target = 5;
    Node* found = tree.search(target);
    if (found)
        cout << "Node with value " << target << " found!" << endl;
    else
        cout << "Node with value " << target << " not found." << endl;

    return 0;
}

