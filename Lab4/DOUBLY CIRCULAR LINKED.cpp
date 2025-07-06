/*
NUR ADWA NAYLI BINTI ZULKAINI
22011769
L4

DOUBLY CIRCULAR
*/

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    Node *next_ptr;
    Node *prev_ptr;

    Node(string name, Node *next_ptr = nullptr, Node *prev_ptr = nullptr)
    { // Constructor with default nullptr for both pointers
        this->name = name;
        this->next_ptr = next_ptr;
        this->prev_ptr = prev_ptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList(Node *head = nullptr)
    { // Constructor initializes head and tail for circular list
        this->head = head;
        this->tail = head;
        if (head)
        {
            head->next_ptr = head; // Point to itself
            head->prev_ptr = head; // Point to itself
        }
    }

    void add_element(Node *node)
    {
        if (!node)
            return; // Check for null pointer

        node->next_ptr = nullptr;
        node->prev_ptr = nullptr;

        if (!head)
        { // If list is empty
            head = node;
            tail = node;
            node->next_ptr = node; // Point to itself
            node->prev_ptr = node; // Point to itself
        }
        else
        {
            // Insert at end (before head in circular list)
            node->next_ptr = head; // New node points to head
            node->prev_ptr = tail; // New node points back to tail
            tail->next_ptr = node; // Current tail points to new node
            head->prev_ptr = node; // Head points back to new node
            tail = node;           // Update tail to new node
        }
    }

    void display_list()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *current = head;
        do
        {
            cout << current->name << " <-> ";
            current = current->next_ptr;
        } while (current != head); // Stop when back to head
        cout << "(back to head)" << endl;
    }

    void delete_by_value(string val)
    {
        if (!head)
            return; // Empty list

        Node *current = head;
        Node *to_delete = nullptr;

        // Find the node to delete
        do
        {
            if (current->name == val)
            {
                to_delete = current;
                break;
            }
            current = current->next_ptr;
        } while (current != head);

        if (!to_delete)
            return; // Value not found

        // Special case: only one node
        if (head == tail && head->name == val)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        // General case
        to_delete->prev_ptr->next_ptr = to_delete->next_ptr; // Link previous to next
        to_delete->next_ptr->prev_ptr = to_delete->prev_ptr; // Link next to previous

        // Update head or tail if necessary
        if (to_delete == head)
            head = to_delete->next_ptr;
        if (to_delete == tail)
            tail = to_delete->prev_ptr;

        delete to_delete;
    }

    // Getter for head to allow memory cleanup in main
    Node *get_head() const
    {
        return head;
    }
};

int main()
{
    // Create nodes dynamically
    Node *node1 = new Node("Ali");
    Node *node2 = new Node("Ahmed");
    Node *node3 = new Node("Alee");

    // Create linked list and add nodes
    LinkedList linkedlst(node1);
    linkedlst.add_element(node2);
    linkedlst.add_element(node3);

    // Display the list
    linkedlst.display_list();

    // Example of deletion
    linkedlst.delete_by_value("Ahmed");
    cout << "After deleting Ahmed: ";
    linkedlst.display_list();

    // Clean up memory
    if (linkedlst.get_head())
    {
        Node *current = linkedlst.get_head();
        Node *start = current;
        do
        {
            Node *temp = current;
            current = current->next_ptr;
            delete temp;
        } while (current != start); // Stop when back to start
    }

    return 0;
}