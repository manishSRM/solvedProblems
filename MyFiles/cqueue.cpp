#include<iostream>
#include<stdio.h>

using namespace std;
const int size = 50;
 
void push (int queue[], int &rear, int &front, int item) {
    if (rear == front - 1 || (front == 0 && rear == size - 1)) {
        printf ("No space of insert element\n");
        return;
    }
    if (rear == size - 1)
        rear = 0;
    else if (rear == -1)
        rear = front = 0;
    else
        ++rear;
    queue[rear] = item;
}

void displayQueue (const int queue[], const int &rear, const int &front) {
    int m = front, n = rear;
    while (m != n) {
        printf ("%d, ", queue[m]);
        m = (m + 1) % size;
    }
    printf ("%d, ", queue[m]);
    return;
}

int empty (int &front) {
    if (front == -1)
        return 1;
    return 0;
}

int pop (int queue[], int &front, int &rear, int &element) {
    if (empty (front)) {
        printf ("Nothing to delete\n");
        return 0;
    }
    element = queue[front];
    if (front == rear)
        front = rear = -1;
    else if (front == size - 1)
        front = 0;
    else
        front++;
    return 1;
}

int main() {
    int queue[size], rear, front, temp, item, r;
    rear = front = -1;
    int value = 30;
    for (int i = 2; i <= 15; i++) {
        push (queue, rear, front, i);
    }
    printf ("Queue is = ");
    displayQueue (queue, rear, front);
    printf ("\n");
    printf("%d, ", empty(front));
	r = pop (queue, front, rear, item);
    printf ("%d\n", r);
    push (queue, rear, front, value);
    r = pop (queue, front, rear, item);
    printf ("%d\n", r);
    displayQueue (queue, rear, front);
    printf ("\n");  
    return 0;   
}
