#include <cstdio>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
};

int cornerWithX (int x, Point &p1, Point &p2) {
    if (x % 2 == 0 && x > 0 || x % 2 != 0 && x < 0) 
        return 0;
    p1.x = p2.x = x;
    if (x % 2 == 0) {
        p1.y = x;
        p2.y = -1 * x;
    }
    else {
        p1.y = -1 * (x - 1);
        p2.y = x + 1;
    }
    return 1;
}

int cornerWithY (int y, Point &p1, Point &p2) {
    if (y % 2 != 0)
        return 0;
    p1.y = p2.y = y;
    if (y > 0) {
        p1.x = -1 * y;
        p2.x = y - 1;
    }
    else {
        p1.x = y;
        p2. x = (-1 * y) + 1;
    }
    return 1;
}

int main () {
    int T;
    scanf ("%d", &T);
    while (T--) {
        int X, Y;
        scanf ("%d %d", &X, &Y);
        Point p1, p2;
        int check1 = cornerWithX (X, p1, p2);
        if ((check1 == 1) && (p1.y <= Y) && (p2.y >= Y)) {
            printf("YES\n");
            continue;
        }
        int check2 = cornerWithY (Y, p1, p2);
        if ((check2 == 1) && (p1.x <= X) && (p2.x >= X)) {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}