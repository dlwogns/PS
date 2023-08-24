#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int N, M, ans;
unordered_set<string>set1;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N>>M;
    while(N--){
        string s; cin>>s;
        string c;
        for(auto e : s){
            c.push_back(e);
            set1.insert(c);
        }
    }
    while(M--){
        string sub; cin>>sub;
        if(set1.find(sub) != set1.end()) ans += 1;
    }
    cout<<ans;
}