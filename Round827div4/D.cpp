#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int main(){
    cin>>T;
    while(T--){
        long long n, q;
        cin>>n>>q;
        vector<int>v;
        vector<long long>pre;
        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            if(i == 0){
                v.push_back(a);
                pre.push_back(a);
            }else{
                v.push_back(max(a, v.back()));
                pre.push_back(pre.back()+a);
            }
        }
        for(int i=0; i<q; i++){
            int step;
            cin>>step;
            int ans = upper_bound(v.begin(), v.end(), step) - v.begin();
            if(ans == 0) cout<<0<<' ';
            else cout<<pre[ans-1]<<' ';
        }
        cout<<'\n';
    }

}