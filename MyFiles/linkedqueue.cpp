#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
    int data;
	node *next;
};

node *queueFront = NULL, *queueRear = NULL;

node *createNewNode (int number) {
	node *newNode = new node;
	newNode -> data = number;
	newNode -> next = NULL;
	return newNode;
}

int front() {
    if (queueFront == NULL) 
        return -1;
    return queueFront -> data;
}

int back() {
    if (queueFront == NULL) 
        return -1;
    return queueRear -> data;
}

void push (int element) {
    node *np = createNewNode (element);
	if (queueFront == NULL)
		queueFront = queueRear = np;
	queueRear -> next = np;
	queueRear = np;
}

void pop () {
	if (queueFront == NULL) {
		printf ("Nothing to delete");
		return;
	}    
	node *ptr = queueFront; 
	queueFront = queueFront -> next;
    if (queueFront == NULL)
        queueRear = NULL;
	delete ptr;
}

void displayQueue (node *ptr) {
	while (ptr != NULL) {
		printf ("%d, ", ptr -> data);
		ptr = ptr -> next;
	}
	printf ("\n");
}

int main() {
    int element;
	for (int i = 1; i < 11; i++) {
		push (i);
	}
	displayQueue (queueFront);
	printf ("\n");
	element = front ();
    if (element == -1) 
        printf ("No Element\n");
    printf ("%d\n", element);
    element = back ();
    if (element == -1)
        printf ("No Element\n");
    printf ("%d\n", element);
    pop ();
	displayQueue (queueFront);
	printf ("\n");	
	return 0;
}
