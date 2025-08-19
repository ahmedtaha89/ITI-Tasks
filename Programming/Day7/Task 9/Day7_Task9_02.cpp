#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int size;
    int* ptr;

public:
    Stack(int s) {
        size = s;
        top = -1;
        ptr = new int[size];
    }

    Stack(const Stack& other) {
        size = other.size;
        top = other.top;
        ptr = new int[size];
        for (int i = 0; i <= top; ++i) {
            ptr[i] = other.ptr[i];
        }
    }

    ~Stack() {
        delete[] ptr;
    }

    void push(int value) {
        if (!isFull()) {
            ptr[++top] = value;
        } else {
            cout << "Stack is Full" << endl;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return ptr[top--];
        } else {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return ptr[top];
        } else {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }
};

int main() {
    Stack s(2);

    s.push(5);
    s.push(10);
    s.push(15);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}
