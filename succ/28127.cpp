#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
using namespace std;
int N, M, vis[1000][1000];
string board[1000][1000];
set<string>ans;
int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            cin>>board[i][j];
        }
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            if(board[i][j] == board[i][j+1]){
                vis[i][j+1] = 1;
                ans.insert(board[i][j]);
            }
            if(board[i][j] == board[i+1][j]){
                vis[i+1][j] = 1;
                ans.insert(board[i][j]);
            }
            if(board[i][j] == board[i][j+2]){
                vis[i][j+2] = 1;
                ans.insert(board[i][j]);
            }
            if(board[i][j] == board[i+2][j]){
                vis[i+2][j] = 1;
                ans.insert(board[i][j]);
            }
        }
    if(ans.empty())
        cout<<"MANIPULATED";

    for(auto e : ans){
        cout<<e<<'\n';
    }
}