#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
    char data;
     node *next;
};

node *head = NULL, *tail = NULL;

node *createNewNode (char data) {
	node *newNode = new node;
    newNode -> next = NULL;
    newNode -> data = data;
    return newNode;
}

void insertNode_beg (node *nptr) {
    if (head == NULL)
    	head = tail = nptr;
    else {
    	nptr -> next = head; 
        head = nptr;
    }     
}

void delete_beg() {
	if (head == NULL) 
	    printf ("Nothing to delete\n");
    else if (head -> next == NULL) {
        delete head;
        tail = head = NULL;
    }
    else {
		node *temp = head;
		head = head -> next;
		delete temp;
	}          
}

void printList (node *head) {
    if (head != NULL) {
    	printf ("%c\t", head -> data);
        printList (head -> next);
    }
}

void insertNodeAtEnd (node *ptr) {
    if (head == NULL)
        head = tail = ptr;
    else {
        tail -> next = ptr;
        tail = ptr;
    }
}

void deleteCountNodesFromBeginning (int count) {
    for (int i = 0; i < count; i++) {
        delete_beg ();
    }
}

void deleteFromLast () {
    if (head == NULL) {
        printf ("Nothing to delete\n");
        return;
    }
    if (head -> next == NULL ) {
        delete head;
        head = tail = NULL;
        return;
    }
    node *temp = head;
    while (temp -> next -> next != NULL) {
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = NULL;
    tail = temp;
}

int main() {       
	for (int i = 71; i > 71; i--) {
	    node *temp = createNewNode (i);
        temp -> next = head;
        head =  temp;
    }
    printList (head);
    printf ("\n");
    node *np = createNewNode (72);
    //insertNode_beg (np);
    insertNodeAtEnd (np);
    //delete_beg ();
    //deleteFromLast ();
    //deleteCountNodesFromBeginning (5);
    printList (head);
    printf ("\n");
    return 0;     
}

