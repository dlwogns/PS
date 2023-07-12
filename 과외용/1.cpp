#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
ll S, T, D, ans=100001;
ll arr[100001];
int main(){
    cin>>S>>T>>D;
    for(ll i=1; i<=D; i++){
        ll w; cin>>w;
        arr[i] = w + arr[i-1];
        if(arr[i] + S <= T) ans = min(ans,i);
    }
    if(ans != 100001){
        cout<<ans; return 0;
    }

    if(arr[D] >= 0){
        cout<<"-1"; return 0;
    }
    ll ans2= 0;
    ll lo = 1, hi = 100000;
    while(lo <= hi){
        ll mid = (lo+hi)/2;
        ll check = 0;
        // loop or loop-1
        ll sub = S + (mid-1) *arr[D];
        for(int i=1; i<=D; i++){
            if(sub + arr[i] <=T){
                check = 1;
                ans2 = (mid-1)*D+i;
                break;
            }
        }
        if(check)  hi = mid-1;
        else lo = mid+1;
    }
    if(ans2 != 0)
        cout<<ans2;
    else
        cout<<"-1";
}