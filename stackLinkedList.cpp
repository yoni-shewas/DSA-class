#include<iostream>
using namespace std;

struct node
{
    char data;
    node *next;
};

class stack{
    private:
        
        node *head;
        
    public:
        stack(){
            head = NULL;
        }
        bool isEmpty(){
            return (head == NULL);
        }
        void push(char element){
            if(isEmpty()){
                node *tmp = new node;
                tmp -> data = element;
                head = tmp;
                head->next = NULL;
            }
            else{
                node *tmp = new node;
                tmp -> data = element;
                tmp->next = head;
                head = tmp;
            }
        }
        void pop(){
            if(isEmpty()){
                return;
            }
            else{
                head = head->next;
            }
        }
        char top(){
            if(!isEmpty()){
                return (head->data);
            }
            else{
                cout<<"Stack empty";
                return '\0';
            }
        }
};

int main(){
    stack list;

    list.push('t');
    list.push('o');
    cout<<list.top()<<endl;
    list.pop();
    list.push('l');
    cout<<list.top()<<endl;

    return 0;
}
