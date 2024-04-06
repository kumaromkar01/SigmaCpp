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

bool chkPalindrome(){
    // get mid using slow fast approach
    struct Node* slow = head ;
    struct Node* fast = head;
    while(fast!=NULL&&fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    //slow is mid;
    //compare values of first half of strb=ing with second half;
    struct Node* tmp = head;
    while(slow!=NULL && slow->next!=NULL && tmp!=NULL && tmp->next!=NULL){
        if(tmp->val!=slow->next->val){
            cout<<"Not a palindrome";
            return false;

        }
        tmp = tmp->next;
        slow = slow -> next;
    }
    cout<<"true, it is palindrome";
    return true;
}
int main(){
    insert(1);
    insert(2);
    insert(2);
    insert(1);
    chkPalindrome();
    return 0;
}