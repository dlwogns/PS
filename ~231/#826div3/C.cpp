#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int T;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        int n, prefix[2001]={0}, ans = 2001;
        cin>>n;
        for(int i=1; i<=n; i++){
            int a;
            cin>>a;
            prefix[i] = prefix[i-1]+a;
        }
        for(int i=1; i<=n; i++){
            int checkans = 0;
            int checksum = prefix[n]/i;
            int left = 0, right = 1;
            while(right <= n){
                if(prefix[right] - prefix[left] == checksum){
                    checkans = max(checkans, right-left);
                    left = right;
                }
                if(left == n && right == n) break;
                right += 1;
            }
            if(left == n && right == n){
                ans = min(ans, checkans);
            }
        }
        if(ans == 2001) cout<<-1<<'\n';
        else cout<<ans<<'\n';
        
    }
}