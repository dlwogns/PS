#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct cmp{
    bool operator()(pair<int,int>a, pair<int,int>b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};
struct cmp2{
    bool operator()(int a, int b){
        return a > b;
    }
};
priority_queue<pair<int,int>, vector<pair<int,int > >, cmp>pq;
int N;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        int a, b; cin>>a>>b;
        pq.push(make_pair(a, b));
    }
    priority_queue<int, vector<int>, cmp2>check;
    int checkdeadline = pq.top().first;
    long long ans = 0;
    check.push(pq.top().second);
    pq.pop();
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(checkdeadline < cur.first){
            checkdeadline = cur.first;
            check.push(cur.second);
        }else{
            if(check.size() < checkdeadline){
                check.push(cur.second);
            }
            else if(check.top() < cur.second){
                check.pop();
                check.push(cur.second);
            }
        }
    }
    while(!check.empty()){
        ans += check.top();
        check.pop();
    }
    cout<<ans;
}