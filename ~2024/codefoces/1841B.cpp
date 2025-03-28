#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int t;
int main(){
    cin>>t;
    while(t--){
        int q, n; vector<int>v;
        cin>>q;
        for(int i=0; i<q; i++){
            int x; cin>>x;
            if(v.size() < 2){
                v.push_back(x);
                cout<<1;
                n = x;
                continue;
            }
            if(v[1] > v[0]){
                if(x > v[0] && x < v[1]){
                    cout<<0;
                    continue;
                }else{
                    v.pop_back();
                    v.push_back(x);
                    cout<<1;
                    continue;
                }
            }
            if(v[1] < v[0]){
                if(x <= v[0] && x >= v[1]){
                    v.pop_back();
                    v.push_back(x);
                    cout<<1;
                    continue;
                }else{
                    cout<<0;
                    continue;
                }
            }
            if(v[1] == v[0]){
                if(n != v[0]){
                    if(x == v[0]) cout<<1;
                    else cout<<0;
                    continue;
                }else{
                    v.pop_back();
                    v.push_back(x);
                    
                }
            }
        }
        cout<<'\n';
            

    }
}
