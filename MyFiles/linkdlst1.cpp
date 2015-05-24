#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
	char data;
     node *next;
};

node *head = NULL;

 node *createNewNode (char data) {
	node *newNode = new node;
    newNode -> next = NULL;
    newNode -> data = data;
    return newNode;
}

void insertNode_beg (node *nptr) {
    if (head == NULL)
    	head = nptr;
    else {
    	node *temp = head;					
        head = nptr;
        nptr -> next = temp;   
    }     
}

void delete_beg() {
	if (head == NULL) 
	    printf ("Nothing to delete\n");
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
    if (head == NULL) {
        head = ptr;
    }
    else {
        node *temp = head;
        while (temp -> next != NULL) {
            temp = temp -> next;    
        }
        temp -> next = ptr; 
        
    }
}

void deleteCountNodesFromBeginning (int count) {
    for (int i = 0; i < count; i++) {
        if (head == NULL) { 
            printf ("No element to delete\n");
            return;
        }
        else {
            node *temp = head;
            head = head -> next;
            delete temp;
        }	
    }
}


void deleteFromLast () {
    if (head == NULL) {
        printf ("Nothing to delete\n");
        return;
    }
    if (head -> next == NULL ) {
        delete head;
        head = NULL;
        return;
    }
    node *temp = head;
    while (temp -> next -> next != NULL) {
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = NULL;
}

int main() {       
	for (int i = 70; i > 64; i--) {
	    node *temp = createNewNode (i);
        temp -> next = head;
        head =  temp;
    }
    //printList (head);
    // printf ("\n");
    // node *np = createNewNode (72);
    // insertNode_beg (np);
    // insertNodeAtEnd (np);
     delete_beg ();
    // printList (head);
    // printf ("\n");
    // deleteCountNodesFromBeginning (9);
    // deleteFromLast ();
     printList (head);
    // printf ("\n");
    return 0;     
}
