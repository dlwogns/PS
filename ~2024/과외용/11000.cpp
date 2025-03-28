#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int main(){
    cin>>N;
    vector<pair<int,int > >v;
    for(int i=0; i<N; i++){
        int s, t; cin>>s>>t;
        v.push_back(make_pair(s, t));
    }
    sort(v.begin(), v.end());

    priority_queue<int , vector<int>, greater<> >pq; // greater<>, less<>
    for(auto e : v){
        if(pq.empty()){
            pq.push(e.second);
            continue;
        }
        if(pq.top() <= e.first){
            pq.pop();
            pq.push(e.second);
        }else
            pq.push(e.second);
    }
    cout<<pq.size();
}

// 2 3
// 4 5
// 3 5


// 2 3
// 3 5
// 4 5