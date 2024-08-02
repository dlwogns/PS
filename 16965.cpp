#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
int N;
vector<pair<int,int > >v;
int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        int a, b, c; cin>>a>>b>>c;
        if(a == 1) {
            v.push_back(make_pair(b, c));
        }else if(a == 2) {
            queue<int>q;
            int vis[101]={0};
            q.push(b-1);
            vis[b-1] = 1;
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                for(int i=0; i<v.size(); i++) {
                   if((v[i].first < v[cur].first && v[cur].first < v[i].second) || (v[i].first < v[cur].second && v[cur].second < v[i].second)) {
                        if(vis[i] == 0) {
                            vis[i] = 1;
                            q.push(i);
                        }
                    }
                }
            }
            if(vis[c-1] == 1) cout<<"1\n";
            else cout<<"0\n";
        }
    }
}