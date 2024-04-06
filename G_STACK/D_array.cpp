#include <iostream>
#include <climits>
using namespace std;

class stack
{
    int capacity;
    int *arr;
    int top;

public:
    stack(int c)
    {
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }
    void push(int data)
    {
        if (this->top >= this->capacity - 1)
        {
            cout << "overflow" << endl;
            return;
        }
        top++;
        arr[this->top] = data;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "underflow";
            return INT_MIN;
        }
        this->top--;
    }
    int getTop()
    {
        if (this->top == -1)
        {
            cout << "underflow";
            return INT_MIN;
        }
        return this->arr[this->top];
    }
    bool isEmpty()
    {
        return this->top == -1;
    }
    bool size()
    {
        return (this->top)++;
    }
    bool isFull()
    {
        return this->top == this->capacity - 1;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    stack s(4);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while (!s.isEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    return 0;
}
