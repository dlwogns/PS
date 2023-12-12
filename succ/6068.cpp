#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int S, T, N, ans=-1;
vector<pair<int,int>>v;
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>T>>S;
        v.push_back({S, T});
    }
    sort(v.begin(),v.end(),greater<>());
    for(auto e : v){
        if(ans == -1){
            ans = e.first - e.second;
            continue;
        }
        if(e.first < ans)
            ans = e.first - e.second;
        else
            ans -= e.second;
    }
    
    if(ans < 0) cout<<-1;
    else cout<<ans;
    
}