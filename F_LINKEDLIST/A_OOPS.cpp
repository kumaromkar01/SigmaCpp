#include<iostream>
using namespace std;
class Node{
    public: 
     int val;
     Node* next;
     Node(int data){
        val = data;
        next = NULL;
     }

};
void push_front(Node *&head,int val){ //you will get an in built function for this
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void display(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp ->next;
    }
    cout<<"NULL"<<endl;
}
void insertAttail(Node *&head, int val){ 
    Node* newNode = new Node(val);
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;

    }
    temp -> next = newNode;
}
void insertAfter(Node * &head,int val,int pos){  // in built function exists
    Node * newNode = new Node(val);
    if(pos==0){
        newNode -> next = head;
        head = newNode;
        return;
    }
    Node *temp = head;
    int currpos =0;
    while(currpos != pos-1){
        temp = temp -> next;
        currpos++;

    }
    newNode -> next = temp -> next;
    temp ->next = newNode;
}
void updatekth (Node *&head,int k, int val){
        Node *temp = head;
        int currp=0;
        while(currp!=k){
            temp = temp -> next;
            currp++;

        }
        temp -> val = val;
}
void pop_front(Node *&head){    
    Node *temp = head;
    head = head ->next;
    free(temp);
}
void deleteAttail(Node *&head){
    Node *curr = head;
    while(curr->next->next!=NULL){
        curr = curr->next;
    }
    Node *temp = curr -> next;
    curr -> next = NULL;
    free(temp);
}
void deleteionATkth(Node*&head,int pos){
    if(pos==0){
        pop_front(head);
        return;
    }
    int curr =0;
    Node *prev = head;
    while(curr!=pos-1){
        prev = prev -> next;
        curr++;
    }
    Node *temp = prev -> next;
    prev->next = prev->next->next;
    free(temp);
}



int main(){
    Node *newNode = new Node(2);
    push_front(newNode,1);
    insertAttail(newNode,3);
    display(newNode);
    insertAfter(newNode,1,3);
    display(newNode);
    updatekth(newNode,3,4);
    display(newNode);
    pop_front(newNode);
    cout<<"\ndeleting head\n";
    display(newNode);
    deleteAttail(newNode);
    cout<<"\ndeleting tail\n\n";
    display(newNode);
    deleteionATkth(newNode,1);
    display(newNode);

}