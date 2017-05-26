#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <stack>
#include <sstream>
#include <queue>
#include <iomanip>
#include <list>
#include <set>
#include <deque>
#include <bitset>
#include <map>
#include <assert.h>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>

#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)

#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d\n", A)

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *makeList() {
    int n, k;
    cin >> n;
    ListNode *head = NULL, *last = NULL;
    FOR (i, 0, n) {
        cin >> k;
        ListNode *t = new ListNode(k);
        if (last == NULL) {
            head = last = t;
        } else {
            last -> next = t;
            last = t;
        }
    }
    return head;
}

void printList(ListNode *temp) {
    while(temp) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int countAllNodes(ListNode *h) {
    if (!h)
        return 0;
    return countAllNodes(h -> next) + 1;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *newHead = NULL, *newTail = NULL;
    int totalNodes = countAllNodes(head);
    for (int l = 0; l < (totalNodes / k); l++) {
        int count = 0;
        ListNode *subHead = NULL, *subTail = NULL;
        for (int i = 0; i < k && head; i++) {
            count++;
            ListNode *t = head;
            head = head -> next;
            t -> next = NULL;
            if (subTail == NULL) {
                subHead = subTail = t;
            } else {
                t -> next = subHead;
                subHead = t;
            }
        }
        if (newTail == NULL) {
            newHead = subHead;
            newTail = subTail;
        } else {
            newTail -> next = subHead;
            newTail = subTail;
        }
    }
    if (newTail == NULL) {
        newHead = head;
    } else {
        newTail -> next = head;
    }
    return newHead;
}
void rotate(struct ListNode **head_ref, int K) {
    ListNode *current = *head_ref;
    int count = 1;
    while (count < K && current != NULL) {
        current = current -> next;
        count++;
    }
    if (current == NULL) {
        return;
    }
    ListNode *KthNode = current;
    while (current -> next != NULL) {
        current = current -> next;
    }
    current -> next = *head_ref;
    *head_ref = KthNode -> next;
    KthNode -> next = NULL;
}

ListNode* reverse(ListNode *head) {
    ListNode *rHead = NULL;
    while (head) {
        ListNode *temp = head;
        head = head -> next;
        temp -> next = NULL;
        ListNode *temp2 = rHead;
        temp -> next = temp2;
        rHead = temp;
    }
    return rHead;
}

ListNode* rearrangeEvenOdd(ListNode *head) {
    ListNode *odd = NULL,  *oddEnd = NULL, *even = NULL, *evenEnd = NULL;
    while (head) {
        ListNode *t = head;
        head = head -> next;
        t -> next = NULL;
        if ((t->val) % 2) {
            if (oddEnd == NULL) {
                odd = oddEnd = t;
            } else {
                oddEnd -> next = t;
                oddEnd = t;
            }
        } else {
            if (evenEnd == NULL) {
                even = evenEnd = t;
            } else {
                evenEnd -> next = t;
                evenEnd = t;
            }
        }
    }
    if (oddEnd) {
        oddEnd -> next = even;
    }
    if (oddEnd == NULL) {
        head = even;
    } else {
        head = odd;
    }
    return head;
}

int getNthFromLast(ListNode *head, int n) {
    if (head == NULL) {
        return -1;
    }
    ListNode *mainPtr = head;
    ListNode *refPtr = head;
    int c = 0;
    while (c < n) {
        if (refPtr == NULL) {
            return -1;
        }
        refPtr = refPtr -> next;
        c++;
    }
    while (refPtr != NULL) {
        mainPtr = mainPtr -> next;
        refPtr = refPtr -> next;
    }
    return mainPtr -> val;
}

void deleteMiddle(ListNode *head) {
    if (head == NULL) {
        return;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = head;
    while (fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        prev = slow;
        slow = slow -> next;
    }
    prev -> next = prev -> next -> next;
}

ListNode* removeDuplicate(ListNode *head) {
    ListNode *temp = head;
    while (head) {
        ListNode *run = head;
        while (run -> next) {
            if (run -> next -> val == head -> val) {
                run -> next = run -> next -> next;
            } else {
                run = run -> next;
            }
        }
        head = head -> next;
    }
    return temp;
}

int main() {
    ListNode *A = makeList();
    deleteMiddle(A);
    printList(A);
    return 0;
}







