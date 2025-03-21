#include <iostream>

// util
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <stdint.h>

// data structure
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <deque>

#define INTMAX 987654321
#define ll long long
#define pii std::pair<int,int>
#define vi std::vector<int>
#define pll std::pair<long long , long long>
#define vl std::vector<long long>
#define for_N(N) for(int i=0; i<N; i++)

using namespace std;

int V, E, arr[10001];
struct cmp {
    bool operator()(pair<int, pair<int,int > >& a, pair<int, pair<int,int > >& b) {
        return a.first > b.first;
    }
};
priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int > > >, cmp >pq;
ll ans;
int Find(int n) {
    if(arr[n] == n) return n;
    else return arr[n] = Find(arr[n]);
}
void Merge(int a, int b) {
    arr[a] = min(arr[a], arr[b]);
    arr[b] = min(arr[a], arr[b]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for_N(10001) {
        arr[i] = i;
    }
    cin>>V>>E;
    for_N(E) {
        int A, B, C;
        cin>>A>>B>>C;
        pq.push(make_pair(C, make_pair(A, B)));
    }
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int fA = Find(cur.second.first), fB = Find(cur.second.second);
        if(fA == fB) continue;
        ans += cur.first;
        Merge(fA, fB);
    }
    cout<<ans;
}