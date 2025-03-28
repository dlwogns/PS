#include <iostream>
#include <algorithm>
#include <vector>
#define INTMAX 987654321
using namespace std;

int N, M, K, arr[1001], checkAns[1001];
int main() {
    cin>>N>>M>>K;
    for(int i=0; i<K; i++){
        int input; cin>>input;
        arr[input] = 1;
    }
    vector<pair<int,pair<int,int > > >v;
    for(int i=0; i<M; i++) {
        int t, a, b; cin>>t>>a>>b;
        v.push_back(make_pair(t, make_pair(a, b)));
    }
    sort(v.begin(), v.end());
    int ans=0;
    for(auto e : v) {
        pair<int,int> track = e.second;
        if(arr[track.first] && !arr[track.second]) {
            checkAns[track.first] = 1;
            continue;
        }
        if(!ans && arr[track.first] && arr[track.second] && !checkAns[track.first]) ans = track.first;
    }
    if(ans == 0) {
        for(int i=0; i<=N; i++)
            if(arr[i]) ans = i;
    }
    cout<<ans;
}