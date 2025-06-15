/*
NUR ADWA NAYLI BINTI ZULKAINI
22011769

DOUBLY LINKED LIST
- ADD A NOTE
- DISPLAY THE LIST
- DELETE A NODE BY VALUE

*/

#include <iostream>
using namespace std;

struct DNode {
    string name;
    DNode* prev;
    DNode* next;
};

class DoublyLinkedList {
    DNode* head = nullptr;
    DNode* tail = nullptr;

public:
    void insert_node(string name) {
        DNode* node = new DNode;
        node->name = name;
        node->prev = nullptr;
        node->next = nullptr;

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void delete_by_value(string value) {
        DNode* current = head;
        while (current != nullptr) {
            if (current->name == value) {
                if (current->prev != nullptr)
                    current->prev->next = current->next;
                else
                    head = current->next;

                if (current->next != nullptr)
                    current->next->prev = current->prev;
                else
                    tail = current->prev;

                delete current;
                return;
            }
            current = current->next;
        }
    }

    void display_list() {
        DNode* current = head;
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList list;

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

