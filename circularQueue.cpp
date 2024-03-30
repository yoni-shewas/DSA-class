#include<iostream>
using namespace std;

class arrayQueue{
    private:
        int max = 6;
        char list[6];
        int rear;
        int front;
    public:
        arrayQueue(){
            rear = -1;
            front = -1;
        }
        void enqueue(char element){
            if((rear + 1) % max != front){
                if(rear == -1) {
                    rear++;
                    front++;
                } else {
                    rear = (rear + 1) % max;
                }
                list[rear] = element;
            }
            else{
                cout<<"Queue is Full\n";
            }
        }
        void dequeue(){
            if(front != -1){
                if(front == rear){
                    front = rear = -1;
                } else {
                    front = (front + 1) % max;
                }
            }
            else{
                cout<<"Queue is empty\n";
            }
        }
        char top(){
            if(front != -1){
                return list[front];
            }
            else{
                return '\0';
            }
        }
};

int main(){
    arrayQueue a;
    a.enqueue('a');
    a.enqueue('s');
    a.enqueue('d');
    a.dequeue();
    a.dequeue();
    cout<<a.top()<<endl;
    return 0;
}
