#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
int N;
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        string s, lans;
        stack<char>rans;
        cin>>s;
        for(auto c : s){
            if(c == '<'){
                if(lans.empty()) continue;
                rans.push(lans.back());
                lans.pop_back();
            }else if(c == '>'){
                if(rans.empty()) continue;
                lans.push_back(rans.top());
                rans.pop();
            }else if(c=='-'){
                if(lans.empty()) continue;
                lans.pop_back();
            }else
                lans.push_back(c);
        }
        while(!rans.empty()){
            lans.push_back(rans.top());
            rans.pop();
        }
        cout<<lans<<'\n';
    }
}