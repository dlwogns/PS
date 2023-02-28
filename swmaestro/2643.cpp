#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int N, arr[1001], ans;
vector<pair<int,int>>v;
bool cmp(const pair<int,int>l, const pair<int,int>r){
    if(l.first == r.first || l.first == r.second || l.second == r.first || l.second == r.second){
        if(l.first + l.second > r.first + r.second)
            return false;
        return true;
    }
    // if((l.first > r.first && l.first > r.second) && (l.second > r.first && l.second > r.second))
    if(max(l.first, l.second) > max(r.first, r.second))
        return false;
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        int left, right;
        cin>>left>>right;
        v.push_back(make_pair(left, right));
    }
    sort(v.begin(), v.end(), cmp);
    cout<<endl;
    for(auto e : v){
        cout<<e.first<<' '<<e.second;
        cout<<endl;
    }
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++){
            if(!cmp(v[j], v[i]))
                arr[j] = max(arr[j], arr[i]+1); 
        }
    for(int i=0; i<N; i++)
        ans = max(ans, arr[i]);
    cout<<ans+1;
}