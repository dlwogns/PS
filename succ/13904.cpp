#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, ans;
vector<pair<int,int > >v;
priority_queue<int, vector<int>, greater<int> >pq;
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        int d, w;
        cin>>d>>w;
        v.push_back(make_pair(d, w));
    }
    sort(v.begin(), v.end());
    int check_d = 1;
    for(auto e : v){
        if(check_d <= e.first){
            pq.push(e.second);
            check_d += 1;
        }else{
            if(pq.top() > e.second) continue;
            pq.pop(); pq.push(e.second);
        }
    }
    while(!pq.empty()){
        ans += pq.top(); pq.pop();
    }
    cout<<ans;
}