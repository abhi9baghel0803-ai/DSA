#include <iostream>
using namespace std;

class LinkedList {

    struct node {
        int data;
        node* next;
        node* prev;
    };

    node* first, *temp, *ttemp, *p;

public:
    void init() {
        first = NULL;
        temp = NULL;
        ttemp = NULL;
        p = NULL;
    }

    void create_first(int x) {
        first = new node;
        first->data = x;
        first->next = first;
        first->prev = first;
    }

    void Addnode(int x) {
        temp = first->prev;

        ttemp = new node;
        ttemp->data = x;

        ttemp->next = first;
        first->prev = ttemp;

        temp->next = ttemp;
        ttemp->prev = temp;
    }
    void deleteNode(int x) {
        if (first == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        node* current = first;
        node* previous = NULL;

        do {
            if (current->data == x) {
                if (previous != NULL) {
                    previous->next = current->next;
                    current->next->prev = previous;
                } else {
                    // Deleting the first node
                    first = current->next;
                    first->prev = current->prev;
                    current->prev->next = first;
                }
                delete current;
                cout << "Node with value " << x << " deleted." << endl;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != first);

        cout << "Node with value " << x << " not found." << endl;
    }

    void deletefirst() {
        if (first == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        node* toDelete = first;

        if (first->next == first) {
            // Only one node in the list
            first = NULL;
        } else {
            first->prev->next = first->next;
            first->next->prev = first->prev;
            first = first->next;
        }

        delete toDelete;
        cout << "First node deleted." << endl;
    }
    void deleteLast() {
        if (first == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        node* toDelete = first->prev;

        if (first->next == first) {
            // Only one node in the list
            first = NULL;
        } else {
            toDelete->prev->next = first;
            first->prev = toDelete->prev;
        }

        delete toDelete;
        cout << "Last node deleted." << endl;
    }
    void addBeforeFirst(int x) {
        if (first == NULL) {
            create_first(x);
            return;
        }

        node* newNode = new node;
        newNode->data = x;
        newNode->next = first;
        newNode->prev = first->prev;
        first->prev->next = newNode;
        first->prev = newNode;
        cout << "Node with value " << x << " added before the first node." << endl;
    }
    void addAfterLast(int x) {
        if (first == NULL) {
            create_first(x);
            return;
        }

        node* newNode = new node;
        newNode->data = x;
        newNode->next = first;
        newNode->prev = first->prev;
        first->prev->next = newNode;
        first->prev = newNode;
        cout << "Node with value " << x << " added after the last node." << endl;
    }
    void swap(int x, int y) {
        if (x == y) {
            return;
        }

        node* nodeX = NULL;
        node* nodeY = NULL;
        node* temp = first;

        do {
            if (temp->data == x) {
                nodeX = temp;
            } else if (temp->data == y) {
                nodeY = temp;
            }
            temp = temp->next;
        } while (temp != first);

        if (nodeX == NULL || nodeY == NULL) {
            cout << "One or both nodes not found." << endl;
            return;
        }

        // Swap the data of the two nodes
        int tempData = nodeX->data;
        nodeX->data = nodeY->data;
        nodeY->data = tempData;

        cout << "Nodes with values " << x << " and " << y << " swapped." << endl;
    }

    void display() {
        if (first == NULL) {
            cout << "List is empty";
            return;
        }

        node* temp = first;

        do {
            cout << temp->data << " "<<endl;
            temp = temp->next;
        } while (temp != first);

        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.init();
    list.create_first(10);
    list.Addnode(20);
    list.Addnode(30);
    list.Addnode(40);
    list.Addnode(50);
    list.Addnode(60);
    list.Addnode(70);
    list.display();
    list.deleteNode(20);
    list.display();
    list.deletefirst();
    list.display();
    list.deleteLast();
    list.display();
    list.addBeforeFirst(5);
    list.display();
    list.addAfterLast(80);
    list.display();
    list.swap(30, 50);
    list.display();
    return 0;
}

