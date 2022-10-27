#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, C, M, arr[2001], ans;
vector<pair<int,pair<int,int>>>v;
int main(){
    cin>>N>>C>>M;
    for(int i=0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        v.push_back({b,{a,c}});
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        auto cur = v[i];
        int check = C;
        for(int j = cur.second.first; j<cur.first; j++){
            check = min(check, C-arr[j]);
        }
        for(int j = cur.second.first; j<cur.first; j++){
            arr[j] += min(check, cur.second.second);
        }
        ans += min(check, cur.second.second);
    }
    cout<<ans;
}