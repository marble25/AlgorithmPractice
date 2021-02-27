//
// Created by 이지호 on 21. 2. 21..
//

#include <cstdlib>
#include <cstdio>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insert(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = x;
    newNode -> next = head;
    head = newNode;
}

int search(int x) {
    Node* current = head;
    while(current->next != NULL) {
        if(current -> data == x) {
            return 1;
        }
        current = current -> next;
    }
    return 0;
}

void del() {
    Node* delNode = head;
    head = head -> next;
    free(delNode);
}

void print() {
    Node* current = head;
    while(current->next != NULL) {
        printf("%d->", current->data);
        current = current -> next;
    }
    if(current != NULL) {
        printf("%d", current->data);
    }
    printf("\n");
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    printf("%d\n", search(3));
    del();
    printf("%d\n", search(3));
    printf("%d\n", search(2));
    print();
    return 0;
}

