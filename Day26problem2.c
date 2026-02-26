#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int val;
    struct Node *prev, *next;
} Node;
typedef struct {
    Node *head;
    Node *tail;
    int size;
} MyLinkedList;
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = malloc(sizeof(MyLinkedList));
    obj->head = obj->tail = NULL;
    obj->size = 0;
    return obj;
}
Node* newNode(int val) {
    Node* n = malloc(sizeof(Node));
    n->val = val;
    n->prev = n->next = NULL;
    return n;
}
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size) return -1;
    Node* cur;
    if(index < obj->size / 2) {
        cur = obj->head;
        for(int i = 0; i < index; i++) cur = cur->next;
    } else {
        cur = obj->tail;
        for(int i = obj->size-1; i > index; i--) cur = cur->prev;
    }
    return cur->val;
}
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* n = newNode(val);
    n->next = obj->head;

    if(obj->head) obj->head->prev = n;
    obj->head = n;

    if(obj->size == 0) obj->tail = n;
    obj->size++;
}
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* n = newNode(val);
    n->prev = obj->tail;

    if(obj->tail) obj->tail->next = n;
    obj->tail = n;

    if(obj->size == 0) obj->head = n;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index < 0 || index > obj->size) return;
    if(index == 0) { myLinkedListAddAtHead(obj, val); return; }
    if(index == obj->size) { myLinkedListAddAtTail(obj, val); return; }

    Node* cur = obj->head;
    for(int i = 0; i < index; i++) cur = cur->next;

    Node* n = newNode(val);
    n->prev = cur->prev;
    n->next = cur;

    cur->prev->next = n;
    cur->prev = n;

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size) return;

    Node* cur;
    if(index < obj->size / 2) {
        cur = obj->head;
        for(int i = 0; i < index; i++) cur = cur->next;
    } else {
        cur = obj->tail;
        for(int i = obj->size-1; i > index; i--) cur = cur->prev;
    }

    if(cur->prev) cur->prev->next = cur->next;
    else obj->head = cur->next;

    if(cur->next) cur->next->prev = cur->prev;
    else obj->tail = cur->prev;

    free(cur);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* cur = obj->head;
    while(cur) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(obj);
}
