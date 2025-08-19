#include <iostream>
using namespace std;

#define Max 2

class Stack {
private:
    int data[Max];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (!isFull()) {
            data[++top] = x;
        } else {
            cout << "Stack is Full" << endl;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return data[top--];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return data[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == Max - 1;
    }
};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);  // Stack is Full

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;  // Stack is empty

    return 0;
}
