#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class linkedList {
private:
    Node* head, * tail;

public:
    linkedList() {
        head = NULL;
        tail = NULL;
    }

    void addNode(char n) {
        Node* tmp = new Node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tmp;
        }
    }

    void display() {
        Node* tmp;
        tmp = head;
        while (tmp != NULL) {
            cout << tmp->data;
            tmp = tmp->next;
        }
    }

    bool isEmpty() {
        return (head == NULL);
    }

    void push(char element) {
        Node* tmp = new Node;
        if (isEmpty()) {
            tmp->data = element;
            tmp->next = NULL;
            head = tmp;
        }
        else {
            tmp->data = element;
            tmp->next = head;
            head = tmp;
        }
    }

    void pop() {
        if (!isEmpty()) {
            char tmp = head->data;
            head = head->next;
            
            if (tmp != '(' && tmp != ')') {
                cout << tmp;
            }
        }
    }

    char checkTop() {
        if(isEmpty()){
            return '\0';
        }
        else{
            return head->data;
            }
    
    }

};

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

int main() {
    linkedList a;
    int size;
    string infixNotation;
    cout << "Please input the expression: ";
    cin >> infixNotation;
    size = infixNotation.size();

    for (int i = 0; i < size; i++) {
        if (isalnum(infixNotation[i])) {
            cout << infixNotation[i];
        }
        else if (a.isEmpty()) {
            a.push(infixNotation[i]);
        }
        else if (getPrecedence(a.checkTop()) >= getPrecedence(infixNotation[i]) && (getPrecedence(infixNotation[i]) != 0)) {
            a.pop();
            while (getPrecedence(a.checkTop()) >= getPrecedence(infixNotation[i]) && !a.isEmpty()) {
                a.pop();
            }
            a.push(infixNotation[i]);
        }
        else if (infixNotation[i] == '(') {
            a.push(infixNotation[i]);
        }
        else if (infixNotation[i] == ')') {
            while (a.checkTop() != '(') {
                a.pop();
            }
            a.pop();
        }
        else if (getPrecedence(a.checkTop()) < getPrecedence(infixNotation[i])) {
            a.push(infixNotation[i]);
        }
    }

    while (!a.isEmpty()) {
        a.pop();
    }

    return 0;
}
