#include<iostream>
#include<stdio.h>

using namespace std;

struct vikas {
    int data;                       //self referencial structure                     
    vikas *next; 
 };
 
void printList (vikas *head) {
    while (head != NULL) {
         cout << head -> data << " ";
         head = (head -> next);
    }
}

vikas *createVikas (int data) {
    vikas *newNode = new vikas;
    newNode -> next = NULL;
    newNode -> data = data;
    return newNode;
}

int main () {
    vikas *vikasList = NULL;
    vikasList = createVikas (10);   
    for (int i = 1; i < 5; i++) {
        vikas *temp = createVikas (i);
        temp -> next = vikasList;
        vikasList = temp;
    }
    printList (vikasList);
    return 0;
}
