#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#define MAX 400

using namespace std;

void seperateWordsFromText(const string &text, vector<string> &words) {
    string single = "";
    int i = 0;
    while (i < text.size()) {
        if (text[i] == ';' || text[i] == ',' || text[i] == '.' || text[i] == ' ') {
            if (single != " " && single != "") {
                words.push_back(single);
            }
            single = "";
        } else {
            single += text[i];
        }
        i++;
    }
    return;
}

int main() {
    string text;
    getline(cin, text);
    vector<string> words;
    seperateWordsFromText(text, words);
    map<>
    return 0;
}






