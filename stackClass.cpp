#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX 10

struct stack {
    int items[MAX];
    int top;
    int size;

    void createEmptyStack() {
        this->top = -1;
        this->size = 0;
    }

    int isFull() {
        if (this->top == MAX - 1) {
            return 1;
        } else {
            return 0;
        }
    }

    int isEmpty() {
        if (this->top == -1) {
            return 1;
        } else {
            return 0;
        }
    }

    void push(int newItem) {
        if (isFull()) {
            cout << "Stack Full \n";
        } else {
            this->top++;
            this->items[this->top] = newItem;
        }
        this->size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Empty \n";
        } else {
            cout << "Item popped = " << this->items[this->top];
            this->top--;
        }
        this->size--;
        cout << endl;
    }

    void printStack() {
        cout << "Stack: ";
        for (int i = 0; i < this->size; i++) {
            cout << this->items[i] << " ";
        }
        cout << endl;
    }
};
typedef struct stack st;

int main() {
    st *s = (st *)malloc(sizeof(st));
    s->createEmptyStack();
    s->push(1);
    s->push(2);
    s->printStack();
    s->pop();
    s->printStack();
}
