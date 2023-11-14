#include <iostream>
#include <algorithm>
#include <unordered_map>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
long long N, arr[200001], ans, anscount;
unordered_map<int, long long>um;
unordered_map<int,int>idx;
int main(){
    fastio;
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    for(int i=1; i<=N; i++){
        if(idx.find(arr[i]-arr[i-1]) == idx.end()){
            idx[arr[i]-arr[i-1]] = i;
            um[arr[i]-arr[i-1]] = arr[i]-arr[i-1];
            if(um[arr[i] - arr[i-1]] > ans){
                ans = um[arr[i] - arr[i-1]];
                anscount = 1;
            }else if(um[arr[i] - arr[i-1]] == ans){
                 anscount += 1;
            }
            continue;
        }
        um[arr[i]-arr[i-1]] = max(um[arr[i]-arr[i-1]], arr[i] - arr[idx[arr[i]-arr[i-1]]-1]);
        if(um[arr[i] - arr[i-1]] > ans){
            ans = um[arr[i] - arr[i-1]];
            anscount = 1;
        }else if(um[arr[i] - arr[i-1]] == ans){
            anscount += 1;
        }
    }
    cout<<ans<<' '<<anscount;
}