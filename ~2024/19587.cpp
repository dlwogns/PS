#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N;
priority_queue<int, vector<int>, greater<int> >pq2;
struct cmp
{
    bool operator()(pair<int,int>a, pair<int,int>b){
        return a.first > b.first;
    }
};

priority_queue<pair<int,int>, vector<pair<int,int > >, cmp>pq;

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        int a, b; cin>>a>>b;
        pq.push(make_pair(a, b));
    }
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(pq2.empty()){
            pq2.push(cur.second);
            continue;
        }
        if(cur.first >= pq2.top()){
            pq2.pop();
            pq2.push(cur.second);
            continue;
        }
        pq2.push(cur.second);
    }

    cout<<pq2.size();
}