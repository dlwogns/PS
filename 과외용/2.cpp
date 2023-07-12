#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int S, T, D, ans=100001;
ll arr[100001];
int main(){
    cin>>S>>T>>D;
    for(int i=1; i<=D; i++){
        ll w; cin>>w;
        arr[i] = w + arr[i-1];
        if(arr[i] + S <= T) ans = min(ans,i);
    }
    if(ans != 100001){
        cout<<ans; return 0;
    }
    if(arr[D] >= 0){
        cout<<-1; return 0;
    }
    ll cmp = (T-S)%arr[D];
    if(cmp == 0){
        cout<<(T-S)/arr[D]*D;
        return 0;
    }
    for(int i=1; i<=D; i++){
        if(arr[i] <= cmp){
            cout<<((T-S)/arr[D]*D) + i;
            return 0;
        }
    }
    cout<<-1;
}