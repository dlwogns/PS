#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > v(101);
int n, vis[101], blue[101], white[101], bans, wans;

int main() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        int a; cin>>a;
        while(a--) {
            int b; cin>>b;
            v[i].push_back(b);
        }
    }
    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        blue[i] = 1; bans += 1;
        queue<int>q;
        q.push(i);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(auto e : v[cur]) {
                if(vis[e]) continue;
                vis[e] = 1;
                if(blue[cur]) {
                    white[e] = 1;
                    wans += 1;
                }
                if(white[cur]) {
                    blue[e] = 1;
                    bans += 1;
                }
                q.push(e);
            }
        }

    }
    cout<<bans<<'\n';
    for(int i=1; i<=n; i++)
        if(blue[i]) cout<<i<<' ';
    cout<<'\n';
    cout<<wans<<'\n';
    for(int i=1; i<=n; i++)
        if(white[i]) cout<<i<<' ';

}
