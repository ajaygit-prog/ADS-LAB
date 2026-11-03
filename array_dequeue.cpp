#include <iostream>
using namespace std;

#define SIZE 5

class Deque {
    int arr[SIZE];
    int front, rear;

public:
    Deque() {
        front = rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) ||
               (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else if (front == 0)
            front = SIZE - 1;
        else
            front--;

        arr[front] = x;
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else if (rear == SIZE - 1)
            rear = 0;
        else
            rear++;

        arr[rear] = x;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear)
            front = rear = -1;
        else if (front == SIZE - 1)
            front = 0;
        else
            front++;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[rear] << endl;

        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = SIZE - 1;
        else
            rear--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
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

        cout << "Enter choice: ";
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