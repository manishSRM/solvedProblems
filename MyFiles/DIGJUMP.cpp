#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#define MAX 100010

using namespace std;

char string[MAX];
bool visited[MAX];
int minimumStep[MAX];
bool Array[10];

vector <int> V[10];

void initalizeVisited (int l) {
	for (int i = 0; i < l; i++) { 
		visited[i] = false;
		minimumStep[i] = -1;
	}	
}

void initalizeVisited2 () {
	for (int i = 0; i < 10; i++)
		Array[i] = false;
}

void bfs (int length) {
	queue <int> Q;
	Q.push (1);
	visited[1] = true;
	int first = string[1] - '0';
	minimumStep[1] = 0;
	while (!Q.empty ()) {
		int u = Q.front ();
		Q.pop ();
		int uu3 = string[u] - '0';
		if (Array[uu3] != true) {
			for (int i = 0; i < V[uu3].size (); i++) {
				if (visited[V[uu3][i]] != true) {
					Q.push (V[uu3][i]);
					visited[V[uu3][i]] = true;
					minimumStep[V[uu3][i]] = minimumStep[u] + 1; 
				}
			}
			Array[uu3] = true;	
		}
		if (u - 1 >= 1) {
    		if (visited[u - 1] != true) {
    			Q.push (u - 1);
    			visited[u - 1] = true;
    			minimumStep[u - 1] = minimumStep[u] + 1;	
    		}
		}
		if (u + 1 <= length) {
    		if (visited[u + 1] != true) {
    			Q.push (u + 1);
    			visited[u + 1] = true;
    			minimumStep[u + 1] = minimumStep[u] + 1;
    		}
		}
	}
}		

int minimumSteps (int length) {
	initalizeVisited (length);
	initalizeVisited2 ();
	bfs (length);
	return minimumStep[length];
}

int main () {
	scanf ("%s", string + 1);
	int size = strlen (string + 1);
	for (int i = 1; string[i] != '\0'; i++) {
		int temp = string[i] - '0';
		V[temp].push_back (i);
	}
	printf("%d\n", minimumSteps (size));	
	return 0;
}