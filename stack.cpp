#include <iostream>

using namespace std;

#define MAX 10

// Creating a stack
struct stack {
	int items[MAX];
	int top;
    int size;
};
typedef struct stack st;

void createEmptyStack(st *s) {
	s->top = -1;
    s->size = 0;
}

// Check if the stack is full
int isFull(st *s) {
	if (s->top == MAX - 1) {
		return 1;
	} else {
		return 0;
	}
}

// Check if the stack is empty
int isEmpty(st *s) {
	if (s->top == -1) {
		return 1;
	} else {
		return 0;
	}
}

// Add element into stack
void push(st *s, int newItem) {
	if (isFull(s)) {
		cout << "Stack Full \n";
	} else {
		s->top++;
		s->items[s->top] = newItem;
	}
	s->size++;
}

// Remove element from stack
void pop(st *s) {
	if (isEmpty(s)) {
		cout << "Stack Empty \n";
	} else {
		cout << "Item poppedd = " << s->items[s->top];
		s->top--;
	}
	s->size--;
	cout << endl;
}

// Print Element of stack
void printStack(st *s) {
	cout << "Stack: ";
	for (int i = 0; i < s->size; i++) {
		cout << s->items[i] << " ";
	}
	cout << endl;
}

// Usage
int main() {
	int ch;
	st *s = (st *)malloc(sizeof(st));
	createEmptyStack(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	printStack(s);
	pop(s);
	printStack(s);
}
