#include <iostream>
using namespace std;
struct Node{
    int val;
    struct Node *next;
};
struct Node *head = NULL;
void insert(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = data;
    newNode->next = head;
    head = newNode;
}
void insertatend(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = data;
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}
void insertatp(int data, int pos){
    if (pos == 0)
    {
        insert(data);
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = data;
    int i = 0;
    struct Node *temp = head;
    while (i != pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
int delet(){
    if (head == NULL)
    {
        cout << "empty list" << endl;
        return -1;
    }
    int val = head->val;
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return val;
}
int deleteatend(){
    if (head == NULL)
    {
        cout << "empty list" << endl;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    struct Node *elem = temp->next;
    int val = elem->val;
    temp->next = NULL;
    free(elem);
    return val;
}
void reverse(){
    struct Node *prev = NULL;
    struct Node *curr = head;
    while (curr != NULL)
    {
        struct Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}
void display(){
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->val << "-->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}
//q1
int nth(int n){
    int i=0;
    struct Node* temp = head;
    while(i<n){
        temp = temp -> next;
        i++;
    }
    cout<< "Node : "<< temp -> val <<endl;
}
//q2 check if ll is singly or circular
int checkcycle(){
        struct Node* slow  = head;
        struct Node* fast = head;
        bool cycle = false;
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                cycle = true;
                slow = head;
                break;
            }
        }
        if(cycle == true){
            cout<<"cycle exists";
        }
        else cout<<"no cycle";
}
//q4
int mid(){
    struct Node* fast = head;
    struct Node* slow = head;
    while(fast!= NULL&&fast->next!=NULL){
        slow = slow-> next;
        fast= fast->next->next;
    }
    cout<<"mid : "<<slow->val;
}
int main(){
    display();
    insert(3);
    insert(2);
    insert(1);
    insertatend(4);
    insertatp(33, 2);
    delet();
    deleteatend();
    display();
    reverse();
    display();
    insert(5);
    insert(6);
    insert(7);
    cout<<"current linkedlist"<<endl;
    display();
    cout<<"4rd index from ll";
    nth(4);
    cout<<"middle element :";
    mid();


}