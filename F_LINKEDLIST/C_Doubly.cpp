#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int data)
    {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void insertAtStart(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << "<-->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void insertatEnd(int val)
    {
        Node *newNode = new Node(val);
        if (tail == head)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return;
    }
    void insertAtend(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return;
    }
    void insertAtPosition(int data, int k)
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        int count = 1;
        while (count < k - 2)
        {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next->prev = newNode;
        return;
    }
    void deleteatStart()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "Invalid" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    void deleteatend()
    {
        if (head == NULL)
        {
            cout << "empty" << endl;
        }
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
        return;
    }
};

int main()
{
    List l; // Create a list object, no need for 'new'
    l.insertAtStart(1);
    l.insertAtStart(2);
    l.insertAtStart(3);
    l.insertAtStart(4);
    l.display();
    l.deleteatStart();
    l.display();
    l.deleteatend();
    l.display();
    return 0;
}
