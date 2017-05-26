#include "iostream"
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

char getLetter(int count, int key){

    char map[][4] = { {' '},{' '},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'} };

    return (char)map[key][count];
}

std::string reverse_t9(std::string keys) {
    int press[10];
    fill_n(press, 10, -1);
    vector<char> msg;
    int i =0;
    while(i < keys.length())
    {
        if (keys[i] == ' ')
        {
            i++;
            continue;
        }
        if( (keys[i+1] - '0') != (keys[i] - '0') ){

            press[keys[i] - '0']++;
            //cout << press[keys[i]-'0'] << '\n';
            msg.push_back(getLetter(press[keys[i]-'0'], keys[i]- '0'));
            press[keys[i]-'0'] = -1;
            i++;
            continue;
        }

        press[keys[i]-'0']++;
        i++;
    }

    string s(msg.begin(), msg.end());
    return s;

}

int main()
{
    string s;
    cout << "enter the string\n";
    getline(cin,s);
    cout << reverse_t9(s);
    return 0;
}