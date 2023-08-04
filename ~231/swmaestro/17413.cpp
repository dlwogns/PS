#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
string s;
void out(string s2){
    //거꾸로 출력
    while(!s2.empty()){
        cout<<s2.back();
        s2.pop_back();
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    getline(cin, s);
    string check;
    int c = 0;
    for(auto e : s){
        if(e == ' '){
            if(c){
                check.push_back(' ');
                continue;
            }
            out(check);
            cout<<' ';
            check.clear();
        }else if(e == '<'){
            c = 1;
            if(!check.empty()){
                out(check);
                check.clear();
            }
            check.push_back('<');
        }else if(e == '>'){
            check.push_back('>');
            cout<<check;
            check.clear();
            c = 0;
        }else{
            check.push_back(e);
        }
    }
    if(!check.empty())
        out(check);
}