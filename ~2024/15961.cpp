#include <iostream>
#include <algorithm>
using namespace std;
int N, d, k, c, ans, chk;
int arr[3000001], sushi[3001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>d>>k>>c;
    // 행사 무조건 참여가 조건
    // 0 ~ N-1까지 반복문 돌림.
    // sliding window로 돌려야됨.
    for(int i=0; i<N; i++) cin>>arr[i];
    for(int i=0; i<k; i++) {
        if(sushi[arr[i]] == 0) 
            ans += 1;
        sushi[arr[i]] += 1;
    }
    chk = ans;
    if(sushi[c] == 0) ans += 1;
    int lp = 0, rp = k-1;
    while(lp != N) {
        sushi[arr[lp]] -= 1;
        if(sushi[arr[lp]] == 0) chk -= 1;
        lp += 1;
        
        rp = (rp+1)%N;
        sushi[arr[rp]] += 1;
        if(sushi[arr[rp]] == 1) chk += 1;

        if(sushi[c] == 0) {
            chk += 1;
            ans = max(ans, chk);
            chk -= 1;
        }else {
            ans = max(ans, chk);
        }
    }
    cout<<ans;
}