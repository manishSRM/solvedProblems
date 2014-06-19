#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
    int data;
    node *next;
};

node *head = NULL;

node *createNewNode (int item) {
    node *ptr = new node;
    ptr -> data = item;
    ptr -> next = NULL;
    return ptr;
}

void insert_beg (node *newptr) {
    if(head == NULL) 
        head = newptr;
    else {
        node *temp = head;
        head = newptr;
        newptr -> next = temp;
    }
}

void deleteFromFirst (node *head) {
    if(head == NULL)
        printf("NOTHING TO DELETE\n");
    else {
        node *temp = head;
        head = head -> next;
        delete temp;
    }        
}

void displayList (node *head) {
    while(head != NULL) {
        printf("%d ->", head -> data);
        head = head -> next;
    }
    printf("\n");
}

int main () {
    for(int i = 0; i < 10; i++) {
        node *temp = createNewNode(i);
        temp -> next = head;
        head = temp;
    }
    displayList (head);
    deleteFromFirst (head);
   // printf("%d\n", head -> data);
    displayList(head);
    return 0;
}