#include <iostream>
#include <vector>
using namespace std;

class Queue {
    int front, back;
    vector<int> v;
public:
    Queue() {
        back = -1;
        front = -1;
    }
    void push(int data) {
        if (back == -1) {
            front = 0;
        }
        v.push_back(data);
        back++;
    }
    void pop() {
        if (front == back) {
            v.clear();
            front = -1;
            back = -1;
        }
        else
            front++;
    }
    int getFront() {
        if (front == -1) {
            return -1;
        }
        return v[front];
    }
    bool empty() {
        return front == -1;
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while (!q.empty()) {
        cout << q.getFront()<<" ";
        q.pop();
    }

    return 0;
}
