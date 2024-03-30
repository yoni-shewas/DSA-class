#include<iostream>
using namespace std;

class Stack {
private:
    int top, max;
    char *arr;

public:
    Stack() {
        top = -1;
        max = 10;
        arr = new char[max];
    }

    void push(char element) {
        if (top == max - 1) {
            cout << "Stack is full\n";
        } else {
            top++;
            arr[top] = element;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "can't pop, Stack is empty\n";
        } else {
            top--;
        }
    }

    void displayTop() {
        if (top == -1) {
            cout << "Stack is empty\n";
        } else {
            cout << arr[top] << endl;
        }
    }
};

int main() {
    Stack List;
    List.pop();
    List.push('d');
    List.push('e');
    List.push('t');
    List.displayTop();
    List.pop();
    List.displayTop();
    List.pop();
    List.displayTop();
    List.pop();
    List.displayTop();

    return 0;
}
