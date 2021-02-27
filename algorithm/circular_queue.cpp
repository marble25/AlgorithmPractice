//
// Created by 이지호 on 21. 2. 20..
//

#define MAX_QUEUE_SIZE 100
int queue[MAX_QUEUE_SIZE];
int front = 0, back = -1;

int isEmpty(){
    return front == back + 1;
}
int isFull(){
    return back - front >= MAX_QUEUE_SIZE - 1;
}
int push(int value){
    if(isFull()) return 1;
    back++;
    queue[back % MAX_QUEUE_SIZE] = value;
    return 0;

}
int pop(){
    if(isEmpty()) return 1;
    front++;
    return 0;
}

int getFront() {
    if(isEmpty()) return 0;
    return queue[front % MAX_QUEUE_SIZE];
}

int getBack() {
    if(isEmpty()) return 0;
    return queue[back % MAX_QUEUE_SIZE];
}
