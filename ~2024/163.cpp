#include <iostream>

// util
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <stdint.h>

// data structure
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <deque>

#define INTMAX 987654321
#define ll long long
#define pii std::pair<int,int>
#define vi std::vector<int>
#define pll std::pair<long long , long long>
#define vl std::vector<long long>
#define for_N(N) for(int i=0; i<N; i++)

using namespace std;
int T, dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--) {
        string board[2];
        int N, vis[200003][3]={0}, ans[200003][3]={0}; cin>>N;
        for(int i=0; i<2; i++) cin>>board[i];
        queue<pair<int,int> > q;
        q.push(make_pair(0, 0));
        vis[0][0] = 1;
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            int x = cur.first, y = cur.second;
            for(int dir = 0; dir<4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if(nx < 0 || nx >= 2 || ny < 0 || ny >= N) continue;
                if(vis[nx][ny]) continue;
                int ddx = (board[nx][ny] == '<') ? -1 : 1;
                vis[nx][ny] = 1;
                while(board[nx][ny]) {
                    if(vis[nx][ny+ddx]) break;
                    if(board[nx][ny] != board[nx][ny+ddx]) {
                        ans[nx][ny+ddx] = 1;
                        vis[nx][ny+ddx] = 1;
                        q.push(make_pair(nx, ny+ddx));
                    }else {
                        ny += ddx;
                        vis[nx][ny+ddx] = 1;
                    }
                }
            }
        }
        if(ans[1][N-1]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}