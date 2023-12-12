#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N, dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
vector<vector<int> > vis1(101, vector<int>(101, 0));
vector<vector<int> > vis2(101, vector<int>(101, 0));
string s[101];
void bfs(int x, int y, vector<vector<int >  >& vis, int& ans){
    queue<pair<int,int > >q;
    q.push(make_pair(x, y));
    vis[x][y] = ans;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0||nx>=N||ny<0||ny>=N) continue;
            if(s[nx][ny] != s[cur.first][cur.second]) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = ans;
            q.push(make_pair(nx, ny));
        }
    }
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>s[i];
    int ans1=1, ans2 =1 ;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            if(vis1[i][j]) continue;
            bfs(i, j, vis1, ans1);
            ans1 += 1;
        }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(s[i][j] == 'G') s[i][j] = 'R';

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            if(vis2[i][j]) continue;
            bfs(i, j, vis2, ans2);
            ans2 += 1;
        }
    cout<<ans1-1<<' '<<ans2-1;
    

}