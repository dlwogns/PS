#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int N, arr[101], ans;
vector<pair<int,int> >v;
// bool cmp(pair<int,int> l, pair<int,int> r){
//     if((max(r.first, r.second) >= max(l.first, l.second)) && (min(r.first, r.second) >= min(l.first, l.second)))
//         return true;
//     return false;
// }
bool cmp(pair<int,int>& l, pair<int,int>& r){
    if((max(r.first, r.second) <= max(l.first, l.second)) && (min(r.first, r.second) <= min(l.first, l.second)))
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
        int mi, ma;
        mi = min(left, right);
        ma = max(left, right);
        v.push_back(make_pair(mi, ma));
    }
    sort(v.begin(), v.end(), cmp);
    // std sort를 쓰면 메모리 초과 난다...?
    // for(int i=0; i<N; i++){
    //     for(int j=i+1; j<N; j++)
    //         if(cmp(v[i], v[j])){
    //             pair<int,int> tmp = v[i];
    //             v[i] = v[j];
    //             v[j] = tmp;
    //         }
    // }
    // cout<<endl;
    // for(auto e : v){
    //     cout<<e.first<<' '<<e.second;
    //     cout<<endl;
    // }
    for(int i =0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(!cmp(v[j], v[i])){
                arr[j] = max(arr[j], arr[i]+1);
            }
        }
    }
    // for(int i=0; i<N; i++)
    //     cout<<arr[i]<<endl;
    for(int i=0; i<N; i++)
        ans = max(ans, arr[i]);
    cout<<ans+1;
    
}