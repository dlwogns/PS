#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int N, dx[7] = {1,0,0,1,1,-1,-1}, dy[7]={0,1,-1,1,-1,1,-1}, ans;
vector<string>v;
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        string s; cin>>s;
        v.push_back(s);
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            if(v[i][j] == '.'){
                int vis[2001][2001] = {0}, check = 0;
                queue<pair<int,int > >q;
                q.push(make_pair(i, j));
                vis[i][j] = 1;
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int dir = 0; dir<7; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx<0||nx>=N||ny<0||ny>=N) continue;
                        if(vis[nx][ny]) continue;
                        if(v[nx][ny] == '#') continue;
                        if(v[nx][ny] == 'F'){
                            check = 1;
                            break;
                        }
                        vis[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                    if(check){
                        ans += 1;
                        break;
                    }
                }
            }
        }
    cout<<ans;
}