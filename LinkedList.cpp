#include<iostream>
using namespace std;

struct node
{
    char data;
    node* next;
};

class linkedList{
    private:
        node *head, *tail;
    public:
        linkedList(){
            head = NULL;
            tail = NULL;
        }
        void addNode(char element){
            if( head == NULL ){
                node *tmp = new node;
                tmp->data = element;
                head = tmp;
                tail = tmp;
                tail->next = NULL;
            }
            else{
                node *tmp = new node;
                tmp->data = element;
                tail->next = tmp;
                tail = tmp;
                tail->next = NULL;
            }
        }
        void display(){
            node *tmp = head;
            while( tmp != NULL){
                cout<<tmp->data<<endl;
                tmp = tmp->next;
            }
        }
};
int main(){
    linkedList list;
    list.addNode('t');
    list.addNode('o');
    list.addNode('d');
    list.display();
}
