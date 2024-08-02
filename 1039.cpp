#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
string N; int K, ans;

int main() {
    cin>>N>>K;
    queue<string>q;
    q.push(N);
    while(K--) {
        set<string>s;
        int len = q.size();
        for(int i=0; i<len; i++) {
            string cur = q.front(); q.pop();
            if(s.find(cur) != s.end()) continue;
            s.insert(cur);
            for(int j=0; j<cur.size(); j++)
                for(int k=j+1; k<cur.size(); k++) {
                    if(j==0&&cur[k]=='0') continue;
                    swap(cur[j], cur[k]);
                    q.push(cur);
                    swap(cur[j], cur[k]);
                }
        }
    }
    while(!q.empty()) {
        string cur = q.front(); q.pop();
        if(cur[0] == '0') continue;
        ans = max(ans, stoi(cur));
    }
    if(ans ==0) cout<<-1;
    else cout<<ans;
}