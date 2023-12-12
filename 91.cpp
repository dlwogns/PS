#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>T;
    while(T--){
        int arr[1001][1001]={0}, N, ans[1001]={0};
        cin>>N;
        for(int i=1; i<=N; i++){
            int k; cin>>k;
            for(int j=0; j<k; j++){
                int a; cin>>a;
                arr[a][i] = 1;
                arr[i][a] = 1;
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(arr[i][j]) ans[i] += 1;
            }
        }
        int rank = 0;
        for(int i=1; i<=N; i++){
            if(ans[i] > ans[1]) rank += 1;
        }
        if(rank < 3) cout<<"YES\n";
        else cout<<"NO\n";


    }
}