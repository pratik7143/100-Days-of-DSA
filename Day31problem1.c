#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // Maximum size of stack

int stack[MAX];
int top = -1;

// Function to check if stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}

// PUSH operation
void push(int x) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", x);
    } else {
        stack[++top] = x;
        printf("%d pushed to stack\n", x);
    }
}

// POP operation
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// PEEK operation
int peek() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return -1;
    } else {
        return stack[top];
    }
}

// DISPLAY operation
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    printf("Popped: %d\n", pop());
    printf("Top element: %d\n", peek());

    display();

    return 0;
}