//
// Created by 이지호 on 21. 2. 20..
//

#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE];
int top=-1;

int isEmpty(){
    return top < 0;
}
int isFull(){
    return top >= MAX_STACK_SIZE-1;
}

int push(int value){
    if(isFull()) {
        return 1;
    }
    stack[++top]=value;
    return 0;
}

int pop(){
    if(isEmpty()) {
        return 1;
    }
    top--;
    return 0;
}

int getTop() {
    if(isEmpty()) {
        return 0;
    }
    return stack[top];
}