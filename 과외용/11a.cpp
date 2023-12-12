#include <iostream>
#include <algorithm>
#include <queue>
#define piii pair<int, pair<int,int> > 
using namespace std;
int T;
struct cmp{
    bool operator()(piii p1, piii p2){
        return p1.first > p2.first;
    }
};
priority_queue<piii, vector<piii > , cmp >pq;
int find(int n, int* arr){
    if(arr[n] == n)
        return n;
    return arr[n] = find(arr[n], arr);
}
void merge(int c1, int c2, int* arr){
    int p1 = find(c1, arr);
    int p2 = find(c2, arr);
    if(p1 > p2)
        arr[p1] = p2;
    else
        arr[p2] = p1;
}
int main(){
    cin>>T;
    while(T--){
        int N, M, ans=0; cin>>N>>M;
        for(int i=0; i<M; i++){
            int a, b, t; cin>>a>>b>>t;
            pq.push(make_pair(t, make_pair(a, b)));
        }
        int disset[1001];
        for(int i=0; i<N; i++)
            disset[i] = i;
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            int pa = find(cur.second.first, disset);
            int pb = find(cur.second.second, disset);
            if(pa == pb)
                continue;
            ans += cur.first;
            merge(cur.second.first, cur.second.second, disset);
        }
        cout<<ans<<'\n';
    }
}

