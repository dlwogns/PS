#include <iostream>
#include <iomanip>
using namespace std;
int N, graph[500001];
double cntNum, W;
int main(){
    cin>>N>>W;
    for(int i=0; i<N-1; i++){
        int u, v; cin>>u>>v;
        graph[u] += 1;
        graph[v] += 1;
    }
    
    for(int i=2; i<=N; i++){
        if(graph[i] == 1) cntNum += 1;
    }
    cout<<fixed<<setprecision(10)<<W/cntNum;
}