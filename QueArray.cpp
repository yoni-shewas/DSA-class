#include<iostream>
using namespace std;

class Que {
private:
    int front, rear, max = 10;
    char *arr;

public:
    Que() {
        front = -1;
        rear = -1;
        arr = new char[max];
    }

    void enqueue(char element) {
        if (rear == max - 1) {
            cout << "Queue is full\n";
        } else if (front == -1) {
            front = rear = 0;
            arr[rear] = element;
        } else {
            rear++;
            arr[rear] = element;
        }
    }

    void dequeue() {
        if (front == -1) {
            cout << "Cannot dequeue, queue is empty\n";
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void top() {
        if (front == -1) {
            cout << "Cannot see queue because it's empty\n";
        } else {
            cout << arr[front] << endl;
        }
    }
};

int main() {
    Que list;
    list.enqueue('t');
    list.enqueue('E');
    list.enqueue('D');
    list.top();
    list.dequeue();
    list.top();
    list.dequeue();
    list.top();
    list.dequeue();
    list.top();
    list.dequeue();

    return 0;
}
