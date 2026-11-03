#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class Deque {
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = NULL;
    }

    void insertFront(int x) {
        Node* newNode = new Node{x, front, NULL};

        if (front == NULL)
            rear = newNode;
        else
            front->prev = newNode;

        front = newNode;
    }

    void insertRear(int x) {
        Node* newNode = new Node{x, NULL, rear};

        if (rear == NULL)
            front = newNode;
        else
            rear->next = newNode;

        rear = newNode;
    }

    void deleteFront() {
        if (front == NULL) {
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = front;

        cout << "Deleted: " << temp->data << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;

        delete temp;
    }

    void deleteRear() {
        if (rear == NULL) {
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = rear;

        cout << "Deleted: " << temp->data << endl;

        rear = rear->prev;

        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;

        delete temp;
    }

    void display() {
        Node* temp = front;

        if (temp == NULL) {
            cout << "Deque is Empty\n";
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Deque d;
    int choice, x;

    do {
        cout << "\n1.Insert Front  2.Insert Rear";
        cout << "\n3.Delete Front  4.Delete Rear";
        cout << "\n5.Display  6.Exit\n";

        cin >> choice;

        switch (choice) {
            case 1:
                cin >> x;
                d.insertFront(x);
                break;

            case 2:
                cin >> x;
                d.insertRear(x);
                break;

            case 3:
                d.deleteFront();
                break;

            case 4:
                d.deleteRear();
                break;

            case 5:
                d.display();
                break;

            case 6:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid Choice\n";
        }
    } while (choice != 6);

    return 0;
}