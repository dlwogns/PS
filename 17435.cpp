#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
int m, funcarr[21][200001], Q;
int main(){
    fastio;
    cin>>m;
    for(int i=1; i<=m; i++)
        cin>>funcarr[0][i];
    for(int i=1; i<=20; i++){
        for(int j=1; j<=m; j++){
            funcarr[i][j] = funcarr[i-1][funcarr[i-1][j]];
        }
    }
    cin>>Q;
    while(Q--){
        int n, x; cin>>n>>x;
        for(int i=20; i>=0; i--){
            if(n >= 1 << i){
                n -= 1 << i;
                x = funcarr[i][x];
            }
        }
        cout<<x<<'\n';
    }
}