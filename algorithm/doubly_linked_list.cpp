//
// Created by 이지호 on 21. 2. 27..
//

#include <cstdlib>
#include <cstdio>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void insertHead(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = x;
    newNode -> next = head;
    newNode -> prev = NULL;
    if(head != NULL) {
        head -> prev = newNode;
    }
    head = newNode;
    if(tail == NULL) {
        tail = newNode;
    }
}

void insertTail(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = x;
    newNode -> prev = head;
    newNode -> next = NULL;
    if(tail != NULL) {
        tail -> next = newNode;
    }
    tail = newNode;
    if(head == NULL) {
        head = newNode;
    }
}

void deleteHead() {
    if(head == NULL) return;
    Node* delNode = head;
    head = head ->next;
    if(delNode == tail) {
        tail = NULL;
    }
    free(delNode);
}

void deleteTail() {
    if(tail == NULL) return;
    Node* delNode = tail;
    tail = tail -> prev;
    if(delNode == head) {
        head = NULL;
    }
    free(delNode);
}

int search(int x) {
    Node* current = head;
    while(current != NULL) {
        if(current -> data == x) {
            return 1;
        }
        current = current -> next;
    }
    return 0;
}

void print() {
    Node* current = head;
    while(current != NULL) {
        if(current->next != NULL) {
            printf("%d->", current->data);
        } else {
            printf("%d", current->data);
        }
        current = current -> next;
    }
    printf("\n");
}

int main() {
    insertHead(1);
    insertHead(2);
    insertTail(3);
    insertHead(4);
    print();
    printf("%d\n", search(3));
    deleteHead();
    print();
    printf("%d\n", search(3));
    insertTail(5);
    print();
    printf("%d\n", search(5));
    print();
    deleteHead();
    deleteHead();
    deleteHead();
    deleteTail();
    print();
    return 0;
}
