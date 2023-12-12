#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int N, M;
vector<vector<int> >graph(501);
int arr[501];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int n1, n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    int dist = 0;
    queue<int>q;
    arr[1] = 1;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto e : graph[cur]){
            if(arr[e]) continue;
            arr[e] = arr[cur]+1;
            q.push(e);
            
        }
    }
    int ans = 0;
    for(int i=1; i<=N; i++){
        if(arr[i] <= 3 && arr[i] >= 2)
            ans += 1;
    }
    cout<<ans;


}