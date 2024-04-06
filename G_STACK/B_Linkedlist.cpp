#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class stack {
    Node* head;
    int capacity;
    int currsize;
public:
    stack(int c) {
        this->capacity = c;
        this->currsize = 0;
        head = NULL;
    }

    bool Empty() {
        return this->head == NULL;
    }

    bool isFull() {
        return this->currsize == this->capacity;
    }

    void push(int data) {
        if (isFull()) {
            cout << "Overflow";
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
        this->currsize++;
    }

    int pop() {
        if (this->head == NULL) {
            cout << "Underflow";
            return INT_MIN;
        }
        Node* newNode = this->head->next;
        this->head->next = NULL;
        Node* toremove = this->head;
        int result = toremove->data;
        delete toremove;
        this->head = newNode;
        this->currsize--;
        return result;
    }
    int top(){
        return head->data;
    }
    int size(){
        return this->currsize;
    }
};

int main() {
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.size()<<endl;
    while (!s.Empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
