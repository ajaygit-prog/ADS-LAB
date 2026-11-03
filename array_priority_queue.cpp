#include <iostream>
using namespace std;

#define SIZE 5

class PriorityQueue {
    int arr[SIZE];
    int n;

public:
    PriorityQueue() {
        n = 0;
    }

    void enqueue(int x) {
        if (n == SIZE) {
            cout << "Queue Overflow\n";
            return;
        }

        int i = n - 1;

        while (i >= 0 && arr[i] > x) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = x;
        n++;
    }

    void dequeue() {
        if (n == 0) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[0] << endl;

        for (int i = 0; i < n - 1; i++)
            arr[i] = arr[i + 1];

        n--;
    }

    void display() {
        if (n == 0) {
            cout << "Queue is Empty\n";
            return;
        }

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    PriorityQueue q;
    int choice, x;

    do {
        cout << "\n1.Insert  2.Delete  3.Display  4.Exit\n";
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