#include <iostream>
#include <cstdio>

using namespace std;

struct student {
     int rollnumber;
     char name[50];
     int marks[5];
     char grade;
}; 

int main() {
    student std;
    int total = 0;
    float percent;
    char ch;
    printf ("Roll number = ");
    scanf ("%d", &std.rollnumber);
    printf ("Name = ");
    scanf ("%c", &ch);
    gets (std.name);
    printf ("Marks = ");
    for (int i = 0; i < 5; i++) {
        scanf ("%d", &std.marks[i]);
        total = total + std.marks[i];
    }
    percent = total / 5;     
    if (percent <= 55)
        std.grade = 'C';
    else if (percent <= 75)
        std.grade = 'B';
    else
        std.grade = 'A';       
    printf ("Percenatge = %f\n", percent);
    printf ("Grade = %c\n", std.grade);
    return 0;
}        
            
