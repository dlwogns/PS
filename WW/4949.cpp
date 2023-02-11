#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    while(getline(cin, s) && s!="."){
        vector<char>v;
        for(auto c : s){
            if(c!='('&&c!=')'&&c!='['&&c!=']') continue;
            if(v.empty()) v.push_back(c);
            else{
                if((v.back() == '(' && c == ')') ||(v.back() == '[' && c == ']')) v.pop_back();
                else v.push_back(c);
            }
        }
        if(v.empty()) cout<<"yes\n";
        else cout<<"no\n";
    }
}