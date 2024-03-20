#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long combination[100001][4], ans;
int graph[100001];
void cal_combination(){
    for(int i=0; i<=100000; i++){
        for(int j=0; j<=3; j++){
            if(j > i) break;
            if(j == i || j == 0) combination[i][j] = 1;
            else{
                combination[i][j] = (combination[i-1][j-1] + combination[i-1][j]) % 1000000007;
            }
        }
    }
}
int main(){
    int n, m; cin>>n>>m;
    cal_combination();
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        graph[a] += 1; graph[b] += 1;
    }
    for(int i=1; i<=n; i++){
        ans = (ans + combination[graph[i]][3]) % 1000000007;
    }
    cout<<ans % 1000000007;
}