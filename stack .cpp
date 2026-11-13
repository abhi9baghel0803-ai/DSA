
#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;

// PUSH operation
void push(int value) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed\n";
    }
}

// POP operation
void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
    } else {
        cout << stack[top] << " popped\n";
        top--;
    }
}

// PEEK operation
void peek() {
    if (top == -1) {
        cout << "Stack is Empty\n";
    } else {
        cout << "Top element: " << stack[top] << endl;
    }
}

// DISPLAY operation
void display() {
    if (top == -1) {
        cout << "Stack is Empty\n";
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid Choice\n";
        }
    } while (choice != 5);

    return 0;
}
