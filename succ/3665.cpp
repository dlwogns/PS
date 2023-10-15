#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int T;
int main(){
    cin>>T;
    while(T--){
        int n, m;
        cin>>n;
        vector<int>dist(n+1);
        vector<int>rank(n+1);
        int arr[501][501]={0};
        vector<int>v;
        for(int i=1; i<=n; i++){
            int input;
            cin>>input;
            dist[input] = i-1;
            rank[input] = i;
            v.push_back(input);
        }
        for(int i=0; i<v.size(); i++)
            for(int j=i+1; j<v.size(); j++){
                arr[v[i]][v[j]] = 1;
            }
        cin>>m;
        for(int i=0; i<m; i++){
            int a, b;
            cin>>a>>b;
            if(rank[a] > rank[b]){
                dist[a] -=1;
                dist[b] += 1;
                arr[b][a] = 0;
                arr[a][b] = 1;
            }else if(rank[b] > rank[a]){
                dist[b] -= 1;
                dist[a] += 1;
                arr[a][b] = 0;
                arr[b][a] = 1;
            }
        }
        queue<int>q;
        vector<int>ans;
        int check=0;
        for(int i=1; i<=n; i++){
            if(dist[i] == 0) q.push(i);
        }
        while(!q.empty()){
            // cout<<endl;
            // for(int i=0; i<dist.size(); i++){
            //     cout<<dist[i]<<' ';
            // }
            // cout<<endl;
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            if(!q.empty()){
                check = 1;
                break;
            }
            for(int i=1; i<=n; i++){
                if(arr[cur][i]){
                    dist[i] -= 1;
                    if(dist[i] == 0){
                        q.push(i);
                    }
                }
            }
        }


        if(check)
            cout<<"IMPOSSIBLE\n";
        else if(ans.size() < n)
            cout<<"IMPOSSIBLE\n";
        else{
            for(auto e : ans)
                cout<<e<<' ';
            cout<<'\n';
        }
    }
}