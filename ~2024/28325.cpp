#include <iostream>
#include <vector>
#define ll long long
using namespace std;
ll N, arr[250001], ans;
vector<int>v, dist;
int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
        if(arr[i]) {
            ans += arr[i];
            v.push_back(i);
        }
    }
    if(v.empty()) {
        cout<<N/2;
        return 0;
    }
    else if(v.size() == 1) {
        dist.push_back(N - v.size());
    }else{
        for(int i=0; i<v.size(); i++) {
            if(i == v.size()-1)
                dist.push_back(v[0] + N-1-v[i]);
            else 
                dist.push_back(v[i+1]-v[i]-1);
        }
    }
    for(auto e : dist){
        ans += e/2 + e%2;
    }
    cout<<ans;


}