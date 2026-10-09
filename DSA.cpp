#include <iostream>
using namespace std;

class LinkedList {

    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int value) : data(value), next(NULL), prev(NULL) {}
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
        newNode->prev = temp;
    }

    // Delete node after x
    void deleteAfter(int x) {
        Node* temp = first;

        while (temp != NULL && temp->data != x) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;

        if (toDelete->next != NULL) {
            toDelete->next->prev = temp;
        }

        delete toDelete;
    }

    void deleteBefore(int x) {
        if (first == NULL || first->data == x) {
            return;
        }

        Node* temp = first;
        while (temp != NULL && temp->next != NULL && temp->next->data != x) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            return;
        }

        Node* toDelete = temp;

        if (temp == first) {
            first = first->next;
            if (first != NULL) {
                first->prev = NULL;
            }
        } else {
            temp->prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
        }

        delete toDelete;
    }

    // Insert a new node before the first occurrence of x
    void addBefore(int x, int y) {
        Node* newNode = new Node(y);

        if (first == NULL) {
            return;
        }

        Node* temp = first;
        while (temp != NULL && temp->data != x) {
            temp = temp->next;
        }

        if (temp == NULL) {
            return;
        }

        if (temp == first) {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
            return;
        }

        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    void addAfter(int x, int y) {
        Node* newNode = new Node(y);

        if (first == NULL) {
            return;
        }

        Node* temp = first;
        while (temp != NULL && temp->data != x) {
            temp = temp->next;
        }

        if (temp == NULL) {
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    void addNodes(int n) {
        Node* temp = first;

        while (temp != NULL) {
            Node* newNode = new Node(n);
            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }

            temp->next = newNode;
            temp = newNode->next;
        }
    }

    void swap(int x, int y) {
        if (x == y) {
            return;
        }

        Node* nodeX = NULL;
        Node* nodeY = NULL;
        Node* temp = first;

        while (temp != NULL) {
            if (temp->data == x) {
                nodeX = temp;
            } else if (temp->data == y) {
                nodeY = temp;
            }
            temp = temp->next;
        }

        if (nodeX == NULL || nodeY == NULL) {
            return;
        }

        // Swap the data of the two nodes
        int tempData = nodeX->data;
        nodeX->data = nodeY->data;
        nodeY->data = tempData;
    }

    

    // Display
    void display() {
        Node* temp = first;

        while (temp != NULL) {
            cout << temp->data << " -> "<<endl;
            temp = temp->next;
        }

        cout << "NULL" << endl;
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
    cout << "\n\nAfter deleting node before 30:\n";
    list.display();

    list.addBefore(30, 25);
    cout << "\n\nAfter adding 25 before 30:\n";
    list.display();

    list.addAfter(30, 35);
    cout << "\n\nAfter adding 35 after 30:\n";
    list.display();

    list.addNodes(10000);
    cout << "\n\nAfter adding 10000 after each node:\n";
    list.display();

    list.swap(20, 50);
    cout << "\n\nAfter swapping 20 and 50:\n";
    list.display();

    return 0;
}