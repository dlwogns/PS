#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char oper[4] = {'+','-','*','/'};
unordered_map<int, string>m;

void solve(string& s) {
    if(s.size() == 3) {
        

        return;
    }
    for(int i=0; i<4; i++) {
        s.push_back(oper[i]);
        solve(s);
        s.pop_back();
    }
}
int main() {
    string s = "";
    solve(s);
}

// 4 4 4 4
// * - *
//0 16 16 0
// ***
// 0 16 