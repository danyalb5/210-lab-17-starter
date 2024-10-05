#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// Function prototypes
void addNodeAtHead(Node* &head, float value);
void addNodeAtTail(Node* &head, float value);
void deleteNode(Node* &head, int position);
void insertNode(Node* &head, int position, float value);
void deleteEntireList(Node* &head);
void output(Node *head);

int main() {
    Node *head = nullptr;
    int count = 0;

    // Create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        addNodeAtHead(head, rand() % 100); // Adds nodes to the head
    }
    output(head);

    // Deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry);
    output(head);

    // Inserting a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000);
    output(head);

    // Deleting the entire linked list
    deleteEntireList(head);
    output(head);

    return 0;
}

// Function to add a node at the head
void addNodeAtHead(Node* &head, float value) {
    Node* newVal = new Node;
    newVal->value = value;
    newVal->next = head;
    head = newVal;
}

// Function to add a node at the tail
void addNodeAtTail(Node* &head, float value) {
    Node* newVal = new Node;
    newVal->value = value;
    newVal->next = nullptr;

    if (!head) {
        head = newVal;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newVal;
    }
}

// Function to delete a node at a specific position
void deleteNode(Node* &head, int position) {
    if (!head) return;  // Empty list check

    Node* current = head;
    Node* prev = nullptr;

    // If deleting the head node
    if (position == 1) {
        head = current->next;
        delete current;
        return;
    }

    // Traverse to the node to delete
    for (int i = 1; i < position && current != nullptr; i++) {
        prev = current;
        current = current->next;
    }

    // If position is out of bounds
    if (current == nullptr) return;

    prev->next = current->next;
    delete current;
}

// Function to insert a node after a specific position
void insertNode(Node* &head, int position, float value) {
    Node* newnode = new Node;
    newnode->value = value;

    Node* current = head;
    Node* prev = nullptr;

    // Traverse to the correct position
    for (int i = 1; i <= position && current != nullptr; i++) {
        prev = current;
        current = current->next;
    }

    // Insert between prev and current
    newnode->next = current;
    if (prev != nullptr) {
        prev->next = newnode;
    } else { // Insert at the head if position is 0
        head = newnode;
    }
}

// Function to delete the entire linked list
void deleteEntireList(Node* &head) {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// Function to output the list
void output(Node *head) {
    if (!head) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node* current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
