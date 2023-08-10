#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define ll long long
using namespace std;
ll N, arr[1000001];
deque<ll>dq;
int main(){
    fastio;
    cin>>N;
    for(int i=0; i<N; i++)  cin>>arr[i];
    sort(arr, arr+N);
    for(int i=0; i<N; i++)  dq.push_back(arr[i]);
    deque<ll>ans_dq;
    int check = 0;
    while(!dq.empty()){
        if(dq.size() == 1){
            if(abs(ans_dq.back() - dq.back()) >= abs(ans_dq.front() - dq.back()))
                ans_dq.push_back(dq.back());
            else
                ans_dq.push_front(dq.front());
            break;
        }
        if(!check){
            ans_dq.push_front(dq.back());
            dq.pop_back();
            if(dq.empty()) continue;
            ans_dq.push_back(dq.front());
            dq.pop_front();
            check = 1;
        }else{
            ans_dq.push_back(dq.back());
            dq.pop_back();
            if(dq.empty()) continue;
            ans_dq.push_front(dq.front());
            dq.pop_front();
            check = 0;
        }
    }
    ll ans = 0;
    for(int i=0; i<ans_dq.size()-1; i++)
        ans += abs(ans_dq[i] - ans_dq[i+1]);
    cout<<ans;

}