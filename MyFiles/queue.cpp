#include <iostream>
#include <stdio.h>

using namespace std;
 
const int size = 50;

void pushInQueue (int queue[], int &rear, int &front, int item) {
    if (rear == size - 1) { 
        printf ("No space of insert elemant\n");
        return;
    }    
    else if (rear == -1) {
        queue[++rear] = item;
        ++front;
    }
    else 
        queue[++rear] = item;
}

void displayQueue (const int queue[], const int &rear, const int &front) {
    int m = front, n = rear;
    while (m != n) {
        printf ("%d, ", queue[m++]);
    }
    printf ("%d\n", queue[m--]);      
}

int popInQueue (int queue[], int &front, int &element) {
    if (front == -1) {
        printf ("Nothing to delete\n");
        return 0;
	    }
    element = queue[front++];
    return 1;
}

int main() {
    int queue[size], rear, front, temp, item, r;
    rear = front = -1;
    for (int i = 2; i <= 15; i++) {
        pushInQueue (queue, rear, front, i);
    }
    printf ("Queue is = ");
    displayQueue (queue, rear, front);
    printf ("\n");
    printf ("%d\n", front);
    r = popInQueue (queue, front, item);
    printf ("%d\n", front);
    printf ("%d\n", r);
    displayQueue (queue, rear, front);
    printf ("\n");  
    return 0;   
}
