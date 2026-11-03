#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = x;
        cout << x << " inserted\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[front++] << endl;

        if (front > rear) {
            front = rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, x;

    do {
        cout << "\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                q.enqueue(x);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid Choice\n";
        }
    } while (choice != 4);

    return 0;
}