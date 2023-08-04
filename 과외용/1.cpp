#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string str;
    queue<char> right;
    char a, c;
    cin >> str;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> c;
        if (c == 'L') {
            if (str.empty()) {
                continue;
            }
            else {
                right.push(str.back());
                str.pop_back();
            }
        }
        else if (c == 'D') {
            if (right.empty()) {
                continue;
            }
            else {
                str.push_back(right.front());
                right.pop();
            }
        }
        else if (c == 'B') {
            if (str.empty()) {
                continue;
            }
            else {
                str.pop_back();
            }
        }
        else if (c == 'P') {
            cin >> a;
            str.push_back(a);
        }
    }
    cout << str;
    while (!right.empty()) {
        cout << right.front();
        right.pop();
    }
}