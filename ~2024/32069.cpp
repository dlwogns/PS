#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
long long L, N, K;
unordered_map<long long,int>um;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>L>>N>>K;
    queue<pair<long long,int > >q;
    for(int i=0; i<N; i++){
        long long a; cin>>a;
        q.push(make_pair(a, 0));
    }
    
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        if(K == 0) break;
        if(um.find(cur.first) == um.end()) {
            um[cur.first] = cur.second;
            cout<<cur.second<<'\n'; K-=1;
            if(cur.first+1 <= L)
                q.push(make_pair(cur.first+1, cur.second+1));
            if(cur.first-1 >= 0)
                q.push(make_pair(cur.first-1, cur.second+1));
        }
        
    }
    
}