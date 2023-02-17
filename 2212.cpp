#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int N, K, arr[2000001];
vector<int>v2;
vector<int>v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, K;
    cin>>N>>K;
    for(int i=0; i<N; i++){
        int input;
        cin>>input;
        if(arr[input+1000000]) continue;
        else{
            arr[input+1000000] = 1;
            v.push_back(input);
        }
    }
    sort(v.begin(), v.end());
    for(int i=1; i<v.size(); i++){
        v2.push_back(v[i] - v[i-1]);
    }
    sort(v2.begin(), v2.end(),greater<int>());
    int ans = v.back() - v[0];
    for(int i=0; i<K-1; i++){
        if(i>=v2.size()) break;
        ans -= v2[i];
    }
    cout<<ans;

}