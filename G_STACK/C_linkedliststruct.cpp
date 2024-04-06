#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node *head = NULL;
bool isEmpty()
{
    return head == NULL;
}
void push(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
int pop()
{
    if (head == NULL)
    {
        cout << "underflow";
        return -1;
    }
    Node *toRemove = head;
    int result = toRemove->data;
    head = toRemove->next;
    delete toRemove;
    return result;
}
void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    push(3);
    push(4);
    push(5);
    print();
    return 0;
}
