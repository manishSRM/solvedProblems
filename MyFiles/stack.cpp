#include <iostream>
#include <stdio.h>

using namespace std;

void pushInStack (int stack[], int &top, int item) {
	stack[++top] = item;
}

void displayStack (const int stack[], const int &top) {
    int temp = top;
    while (temp != -1) {
        printf ("%d, ", stack[temp--]);
    }
    printf ("\n");      
}

int popInStack (int stack[], int &top, int &element) {
    if (top == -1) {
        printf ("Nothing to delete\n");
        return 0;
    }
    element = stack[top--];
    return 1;
}

int main() {
    int stack[20], top = -1, temp, item;
    for (int i = 0; i <= 10; i++) {
        pushInStack (stack, top, i);
    }
    printf ("Stack is = ");
    displayStack (stack, top);
    printf ("\n");
    temp = popInStack (stack, top, item);
    printf ("%d\n", temp);
    displayStack (stack, top);
    printf ("\n");  
    return 0;   
}
