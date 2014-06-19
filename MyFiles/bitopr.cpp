#include <cstdio>
#include <iostream>

using namespace std;

int isBitSet (int mask, int k) {
    //returns 1 if kth bit is set in mask otherwise 0
    return ((mask & (1 << k)) != 0);
}

void setBit (int &mask, int k) {
    //set kth bit in mask
    mask |= (1 << k);
}

void clearBit (int &mask, int k) {
    //unset kth bit in mask
    mask &= ~(1 << k);
}

void toggleBit1 (int &mask, int k) {
    //toggle kth bit.. make it 1 if 0, 0 if 1
    if(isBitSet (mask, k)) {
        clearBit (mask, k);
    } else {
        setBit (mask, k);
    }
}

void toggleBit2 (int &mask, int k) {
    mask ^= (1 << k);
}

int countSetBits (int mask) {
    //count number of 1 bits
    int count = 0;
    while(mask) {
        count += (mask & 1);
        mask >>= 1;
    }
    return count;
}

int main () {
    int num = 20;
    printf("%d\n", isBitSet (num, 4));
    return 0;
}    
