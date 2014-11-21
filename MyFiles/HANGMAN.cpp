#include <cstdio>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>  
#include <stack>
#include <queue>
#include <set>
#include <assert.h>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <time.h>

#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)

#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d", A)

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;

int checkIfAllZero (const VI &A) {
    for(int i = 65; i <= 92; i++) {
        if(A[i] != 0)
            return 0;
    }
    return 1;
}

void printCheck(const VI &A) {
    for(int i = 65; i <= 92; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
} 

vector<string> setUpSecretWords() {
    vector<string> myvector;
    string name;
    ifstream myfile("HangmanGame.txt");
    if(!myfile) {
        cout << "ERROR!\n";
        system("pause");
        exit(1);
    }
    while (getline(myfile, name)) {
        myvector.push_back(name);
    }
    return myvector;
}

int getSectretwordindex(vector<string> &V) {
    srand (time(NULL));
    return (rand() % V.size());
}

void initalizeScoreVector(VI &A, string str, char C) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == C) 
            A[i] = C;
    }
    return;    
}

void showStatus(VI &A, string str) {
    printf("CURRENT WORD: ");
    for(int i = 0; str[i] != '\0'; i++) {
        if(A[i] == -1) { 
            printf("_ ");
        } else {
            printf("%c ", str[i]);
        }
    }
    printf("\n");
    return;
}

void printHangmanOldStatus(int matrix[][7]) {
    FOR(i, 0, 7) {
        FOR(j, 0, 7) {
            if(matrix[i][j] != 0) {
                printf("%c", matrix[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printHangman(int matrix[][7], int m, int n, int num) {
    matrix[m][n] = num;
    FOR(i, 0, 7) {
        FOR(j, 0, 7) {
            if(matrix[i][j] != 0) { 
                printf("%c", matrix[i][j]);
            } else { 
                printf(" ");
            }
        }
        printf("\n");
    }
}

void initializeMatrix(int matrix[][7]) {
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            matrix[i][j] = 0;
        }
    }
    matrix[5][1] = matrix[5][2] = matrix[5][3] = matrix[5][4] = matrix[5][5] = matrix[5][6] = 95;
    matrix[0][2] = matrix[0][3] = matrix[0][4] = 95;
    matrix[1][2] = matrix[1][5] = matrix[2][5] = matrix[3][5] = matrix[4][5] = matrix[5][5] = 124;
}

void playGame(vector<string> &V, int secretIndex) {
    string str = V[secretIndex];
    int len = V[secretIndex].size();
    vector <int> checkForCharacters(95, 0), scoreVector(len, -1);
    for(int i = 0; i < len; i++) {
        checkForCharacters[str[i]]++;  
    }
    int limit = 6, flag = 0, matrix[7][7], Array[6], counter = -1;
    VPI A(6);
    A[0] = make_pair(2, 2);
    A[1] = make_pair(3, 2);
    A[2] = make_pair(3, 1);
    A[3] = make_pair(3, 3);
    A[4] = make_pair(4, 1);
    A[5] = make_pair(4, 3);
    Array[0] = 'O';
    Array[1] = '|';
    Array[2] = '/';
    Array[3] = '\\';
    Array[4] = '/';
    Array[5] = '\\';
    char guessChar, C;
    initializeMatrix(matrix);
    printf("\n&&&&&&&&&&&&&&&&&&&&&&&& THIS IS HANGMAN GAME &&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    printf("\nSECRET WORDS = %d\n", len);
    while(limit) {
        if(limit != 6)
            printf("YOUR NEXT GUESS\n");
        scanf("%c%c", &guessChar, &C);
        int findIt = 0;
        if(!checkForCharacters[guessChar]) {
            limit--;
            counter++;  
            printHangman(matrix, A[counter].first, A[counter].second, Array[counter]);
        } else  {
            checkForCharacters[guessChar] = 0;
            findIt = 1;
            printHangmanOldStatus(matrix);
        } 

        if(checkIfAllZero(checkForCharacters)) { 
            flag = 1;
            break;
        }
    
        if(findIt) {
            initalizeScoreVector(scoreVector, str, guessChar);
            printf("YOUR GUESS CHARACTER IS CORRECT\n");
        } else {
            printf("THIS CHARACTER DOESN'T EXIST IN WORD TRY ANYTHING ELSE\n");
        }
        showStatus(scoreVector, str);    
        if(limit)
            printf("%d MORE WRONG ATTEMPTS LEFT\n", limit);
        printf("\n***************************************************************************\n");
    }
    cout << str << endl;
    if(!limit) {
        printf("YOUR GUESS IS WRONG\n");
    } else {
        printf("YOUR GUESS IS CORRECT!\n");
    }
}

int main () {
    vector<string> myvector = setUpSecretWords();
    int sectreIndex = getSectretwordindex(myvector);
    playGame(myvector, sectreIndex);
    return 0;
}