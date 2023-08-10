#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M, sub, board[1001][1001];
int main(){
    cin>>N>>M;
    vector<int>dist(N+1, 0);
    for(int i=0; i<M; i++){
        cin>>sub;
        int arr[1001];
        for(int j=0; j<sub; j++)
            cin>>arr[j];
        for(int j=0; j<sub; j++){
            for(int k=j+1; k<sub; k++)
                board[arr[j]][arr[k]] = 1;
        }
    }
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++){
            if(board[i][j]) dist[j] += 1;
        }
    vector<int>ans;
    queue<int>q;
    for(int i=1; i<=N; i++)
        if(dist[i] == 0) q.push(i);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(int i=1; i<=N; i++)
            if(board[cur][i]){
                dist[i] -= 1;
                if(dist[i] == 0)
                    q.push(i);
            }
    }
    if(ans.size() != N){
        cout<<0;
        return 0;
    }
    for(auto e : ans)
        cout<<e<<'\n';
}