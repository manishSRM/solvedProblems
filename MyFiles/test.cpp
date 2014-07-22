#include <stdio.h>
#include <iostream>

using namespace std;

int maxi, arr[10][10];

void input (){
for (int i = 0; i <= 2; i++) {
for (int j = 0; j <= 2; j++)
scanf("%d",&arr[i][j]) ;

}
}

void Checkcolumn (int c, int d) {
    int counti = 0;
    for (int i = 0; i <= 2; i++) {
if (arr[d][c] >= arr[i][c]) {
counti++;
}
else
break;
}
if (counti == 3) {
cout << arr[d][c];
}
}

void Checkrow (int row) {
int min = arr[row][0], d, c;
for (int j = 0; j <= 2; j++) {
if (arr[row][j] <= min) {
min = arr[row][j];
c = j;
d = row;
}
}
Checkcolumn (c, d);
}


int main () {
input();
for(int i = 0; i <= 2; i++) {
Checkrow(i);
}
return 0;
}
// #include <cstdio>
// #include <algorithm>
// #include <vector>
// #include <stack>
// #include <set>
// #include <iostream>
// #include <utility>
// #include <string.h>
    
// using namespace std;

// struct add {
//     int hour;
//     char colon;
//     int minute;
// } ad1;

// int main () {
//     scanf ("%d %c %d", &ad1.hour, &ad1.colon, &ad1.minute);
//     printf("%d%c%d\n", ad1.hour, ad1.colon, ad1.minute);
//     return 0;
// }