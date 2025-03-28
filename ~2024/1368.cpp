#include <iostream>
#include <algorithm>
#include <queue>
#define INTMAX 987654321
#define pii pair<int, pair<int, int> >
using namespace std;
int N, mincost=INTMAX, arr[301];
long long ans;

struct cmp{ // to compare pq<pii> 
    bool operator()(pii& a, pii& b) {
        return a.first > b.first;
    }
};
priority_queue<pii, vector<pii>, cmp >pq;
// int arr[301], find_t func, union_t func
// disjoint set, Union-find Function
int find_t(int a) {
    if(arr[a] == a) return a;
    else return find_t(arr[a]);
}
void union_t(int a, int b) {
    int p = min(arr[a], arr[b]);
    arr[a] = p; arr[b] = p;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N;
    // initialize disjoint set
    for(int i=0; i<=N; i++)arr[i] = i;

    // push virtual node in pq
    for(int i=1; i<=N; i++) {
        int a; cin>>a; pq.push(make_pair(a, make_pair(0, i)));
    }
    
    // push graph info (edge weight per each nodes)
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) {
            int c; cin>>c;
            if(c)
                pq.push(make_pair(c, make_pair(i, j)));
        }

    while(!pq.empty()) {
        int cost = pq.top().first;
        pair<int,int> p = pq.top().second;
        pq.pop();
        int mp1 = find_t(p.first), mp2 = find_t(p.second);
        // if each nodes parents are same, cycle can occur. so continue;
        if(mp1 == mp2) continue;
        // union nodes
        union_t(mp1, mp2);
        ans += cost;
    }
    cout<<ans;
}