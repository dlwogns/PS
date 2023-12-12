#include <iostream>
#define fastio cin.tie(0)->cout.tie(0)->sync_with_stdio(0)
using namespace std;
int N, M, arr[1001][1001], ans;
int main(){
    cin>>N>>M;
        for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(M == 1){
                if(i%2 == 0) arr[i][j] = 1;
                if(i%2 == 1) arr[i][j] = 2;
                ans = max(ans, arr[i][j]);
                continue;
            }
            if(i%2 == 0 && j%2 == 0) arr[i][j] = 1;
            if(i%2 == 0 && j%2 == 1) arr[i][j] = 2;
            if(i%2 == 1 && j%2 == 0) arr[i][j] = 3;
            if(i%2 == 1 && j%2 == 1) arr[i][j] = 4;
            ans = max(ans, arr[i][j]);
        }
    
    cout<<ans<<'\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }

}


