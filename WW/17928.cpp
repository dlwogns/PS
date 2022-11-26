#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    vector<pair<int,int>>v;
    vector<int>ans(N, -1);
    for(int i=0; i<N; i++){
        int input;     
        cin>>input;
        if(v.empty()){
            v.push_back({input,i});
        }else{
            while(v.back().first < input && !v.empty()){
                ans[v.back().second] = input;
                v.pop_back();
            }
            v.push_back({input, i});
        }
    }
    for(auto e : ans)
        cout<<e<<' ';
}