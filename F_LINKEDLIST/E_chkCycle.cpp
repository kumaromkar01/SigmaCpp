#include<iostream>
using namespace std;

struct Node
{
    int val;
    struct Node* next;
};

void display(struct Node* head)
{
    struct Node* temp = head;
    do
    {
        cout << temp->val << "-->";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
}

bool ckCycle(Node* head)
{
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            cout << "True, and it is cyclic" << endl;
            return true;
        }
    }
    cout << "False" << endl;
    return false;
}

int main()
{
    struct Node* head = new Node;
    struct Node* a = new Node;
    struct Node* b = new Node;
    struct Node* c = new Node;
    struct Node* d = new Node;

    head->val = 1;
    a->val = 2;
    b->val = 3;
    c->val = 4;
    d->val = 5;

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = head; // Make it circular

    display(head);
    ckCycle(head);

    // No need to free the memory since it's a circular linked list
    return 0;
}
