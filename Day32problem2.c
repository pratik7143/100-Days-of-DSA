#include <stdlib.h>
typedef struct {
    int *stack;
    int *minStack;
    int top;
    int capacity;
} MinStack;
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 10000;
    obj->stack = (int*)malloc(sizeof(int) * obj->capacity);
    obj->minStack = (int*)malloc(sizeof(int) * obj->capacity);
    obj->top = -1;
    return obj;
}
void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;
    if (obj->top == 0) {
        obj->minStack[obj->top] = val;
    } else {
        obj->minStack[obj->top] = val < obj->minStack[obj->top - 1] ? val : obj->minStack[obj->top - 1];
    }
}
void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}
int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}
int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}
void minStackFree(MinStack* obj) 
{
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}
