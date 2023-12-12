#include <iostream>
using namespace std;
int T, N, W, arr[20001];
long long dp[4][20001];
int main(){
    cin>>T;
    while(T--){
        cin>>N>>W;
        for(int i=1; i<=2*N; i++){
            cin>>arr[i];
        }
        // 0 -> 선택 X, 1 -> 왼, 2 -> 오, 3 -> 상하
        

    }
}

// 완탐 -> 3방향, 선택x 탐색 순열 -> 4^N
// 