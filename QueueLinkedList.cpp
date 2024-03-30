#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Queue {
private:
    Node* head,*tail;

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    void display() {
        Node* tmp;
        tmp = head;
        while (tmp != NULL) {
            cout << tmp->data;
            tmp = tmp->next;
        }
    }
    bool isEmpty(){
        return (head==NULL);
    }

    void enqueue (char element){
        if(isEmpty()){
            Node* tmp = new Node();
            head = tmp;
            tail = tmp;
            head->data = element;
            tail->next = NULL;
        }
        else{
            Node* tmp = new Node();
            tmp->data = element;
            tail->next = tmp;
            tail = tmp;
            tail->next = NULL;
        }
    }
    void dequeue(){
        if(!isEmpty()){
            head =  head->next;
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

int main() {
    Queue a;
    a.enqueue('e');
    a.enqueue('c');
    a.enqueue('d');
    a.display();
    a.dequeue();
    a.display();

    return 0;
}
