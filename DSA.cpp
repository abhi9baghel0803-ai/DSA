#include <iostream>
using namespace std;

class LinkedList {

    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = NULL;
        }
    };

    Node* first = NULL;

public:

    // Insert at end
    void insert(int value) {
        Node* newNode = new Node(value);

        if (first == NULL) {
            first = newNode;
            return;
        }

        Node* temp = first;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Delete node after x
    void deleteAfter(int x) {

        Node* temp = first;

        while (temp != NULL && temp->data != x) {
            temp = temp->next;
        }

        // x not found or x is the last node
        if (temp == NULL || temp->next == NULL) {
            return;
        }

        Node* ttemp = temp->next;

        temp->next = ttemp->next;

        delete ttemp;
    }
    void deleteBefore(int x) {

    // If first node contains x, nothing to delete before it
    if (first == NULL || first->data == x) {
        return;
    }

    Node* temp = first;
    Node* ttemp = NULL;

    while (temp->next != NULL && temp->next->data != x) {
        ttemp = temp;
        temp = temp->next;
    }

    // x not found
    if (temp->next == NULL) {
        return;
    }

    // temp is the node before x
    if (temp == first) {
        first = first->next;
        delete temp;
        return;
    }

    ttemp->next = temp->next;
    delete temp;
    }
    

    // Display
    void display() {
        Node* temp = first;

        while (temp != NULL) {
            cout << temp->data << " -> "<<endl;
            temp = temp->next;
        }

        cout << "NULL";
    }
};

int main() {

    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);
    list.insert(60);
    list.insert(70);
    list.insert(80);

    cout << "Before deletion:\n";
    list.display();

    list.deleteAfter(30);

    cout << "\n\nAfter deleting node after 30:\n";
    list.display();

    list.deleteBefore(30);
    cout<<"\n\nAfter deleting node before 30:\n";
    list.display();

    return 0;
}