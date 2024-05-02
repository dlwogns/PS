#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000001
using namespace std;

int N, height[100001], isAdapter[100001], ans;
vector<vector<int> > v(MAX);
int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        int src, dest; cin>>src>>dest;
        height[src] += 1; height[dest] += 1;
        v[src].push_back(dest);
        v[dest].push_back(src);
    }
    queue<int>q;
    for(int i=1; i<=N; i++) {
        if(v[i].size() == 1) q.push(i);
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(isAdapter[cur]) continue;
        
    }

} 