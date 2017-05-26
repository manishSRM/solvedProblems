#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    FILE *fp;
    char buff[200];
    fp = fopen("learn.txt", "ra+");
    fprintf(fp, "This is test of fprintf..");
    fputs("This is a test of fputs...\n", fp);
    fscanf(fp, "%s", buff);
    cout << buff << endl;
    fgets(buff, 200, fp);
    cout << buff << endl;
    return 0;
}