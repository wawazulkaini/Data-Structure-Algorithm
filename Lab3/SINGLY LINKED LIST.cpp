/*
NUR ADWA NAYLI BINTI ZULKAINI
22011769

SINGLY LINKED LIST
- ADD A NOTE
- DISPLAY THE LIST
- DELETE A NODE BY VALUE

*/

#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next_pointer;
};

class SinglyLinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    void insert_node(string name) {
        Node* node = new Node;
        node->name = name;
        node->next_pointer = nullptr;

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next_pointer = node;
            tail = node;
        }
    }

    void delete_by_value(string value) {
        if (head == nullptr) return;

        if (head->name == value) {
            Node* temp = head;
            head = head->next_pointer;
            delete temp;
            if (head == nullptr) tail = nullptr;
            return;
        }

        Node* current = head;
        while (current->next_pointer != nullptr && current->next_pointer->name != value) {
            current = current->next_pointer;
        }

        if (current->next_pointer != nullptr) {
            Node* temp = current->next_pointer;
            current->next_pointer = temp->next_pointer;
            if (temp == tail) tail = current;
            delete temp;
        }
    }

    void display_list() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next_pointer;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insert_node("WAWA");
    list.insert_node("NAYLI");
    list.insert_node("ZULKAINI");

    cout << "Before deletion:" << endl;
    list.display_list();

    list.delete_by_value("NAYLI");

    cout << "After deletion:" << endl;
    list.display_list();

    return 0;
}


