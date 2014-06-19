#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
    char data;
     node *next;
};

node *createNewNode (char data) {
	node *newNode = new node;
    newNode -> next = NULL;
    newNode -> data = data;
    return newNode;
}

void insertNode_beg (node **headptr, node *nptr) {
    if (*headptr == NULL)
    	*headptr = nptr;
    else {
    	node *temp = *headptr;      	
        *headptr = nptr;
        nptr -> next = temp;   
    }     
}

void delete_beg (node **headptr) {
	if (*headptr == NULL) 
	    printf ("Nothing to delete\n");
    else {
		node *temp = *headptr;
		*headptr = (*headptr) -> next;
		delete temp;
	}          
}

void printList (node *head) {
    if (head != NULL) {
    	printf ("%c\t", head -> data);
        printList (head -> next);
    }
}

void deleteCountNodesFromBeginning (node **headptr, int count) {
    for (int i = 0; i < count; i++) {
        if (*headptr == NULL) { 
            printf ("No element to delete\n");
            return;
        }
        else {
            node *temp = *headptr;
            *headptr = (*headptr) -> next;
            delete temp;
        }
    }
}

int main() {
    node *head = NULL;
	for (int i = 71; i > 64; i--) {
	    node *temp = createNewNode (i);
        temp -> next = head;
        head =  temp;
    }
    printList (head);
    printf ("\n");
    node *np = createNewNode (110);
    insertNode_beg (&head, np);
    printList (head);
    printf ("\n");
    delete_beg (&head);
    deleteCountNodesFromBeginning (&head, 7);
    printList (head);
    printf ("\n");
    return 0;     
}
