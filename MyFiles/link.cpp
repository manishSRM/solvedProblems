#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
    int data;
    node *next;
};

node *top = NULL;

int topElement() {
    if (top == NULL) {
        printf ("No Element\n");
        return -1;
    }
    return top -> data;
} 

int empty() {
    if (top == NULL) 
        return 1;
    return 0;    
}  

node *createNewNode (int item) {
    node *newNode = new node;
    newNode -> data = item;
    newNode -> next = NULL;
    return newNode;
}

void push (int element) {
    node *newPtr =createNewNode (element); 
    newPtr -> next = top;
    top = newPtr;
}

void displayStack (node *np) {
    while (np != NULL) {
        printf ("%d\t", np -> data);
        np = np -> next;
    }
    printf ("\n");
}

void pop () {
    if (top == NULL) {
        printf ("Nothing to delete\n");
        return;
    }
    node *temp = top;
    top = top -> next;
    delete temp;
}

int main() {
    int temp;
    for (int i = 1; i < 11; i++) {
        push (i);   
    }
    displayStack (top);
    printf ("\n");
    temp = topElement();
    if (temp != -1)
        printf ("%d\n", temp);

    if (empty())
        printf ("Stack is empty\n");
    else 
        printf ("Stack is not empty");

    while (!empty())
        pop ();

    displayStack (top);
    printf ("\n");
    return 0;
}