#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *next;
    Node(int data){
        val = data;
        next = NULL;
    }
};
class Queue{
    public :
    Node* head;
    Node* tail;
    Queue(){
        head = NULL;
        tail = NULL;
    }
    void push(int data){
        Node *newNode = new Node(data);
        if(head == nullptr){
            head = tail = newNode;
        }
        tail -> next = newNode;
        tail = newNode;
    }
    void pop(){
        if(head==NULL){
            cout<<"empty queue";
            return;

        }
        Node *newhead = head -> next;
        Node *oldhead = head;
        oldhead->next = NULL;
        free(oldhead);
        head = newhead;

    }
    bool empty(){
        return this->head==NULL;
    }
    int font(){
        if(head==NULL) return -1;
        return head->val;
    }
};
int main(){
    Queue s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while(!s.empty()){
        cout<<s.font()<<" ";
        s.pop();
    }
}