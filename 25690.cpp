#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long n, wb[100001][2], dp[100001][2], chk, ans;
vector<vector<long long > > v(100001);
void solve(int node) {
    if(v[node].empty()) {
        dp[node][0] = wb[node][0];
        dp[node][1] = wb[node][1];
        return;
    }
    dp[node][0] = wb[node][0];
    dp[node][1] = wb[node][1];
    for(auto e : v[node]) {
        solve(e);
        dp[node][0] +=  min(dp[e][0], dp[e][1]);
        dp[node][1] +=  dp[e][0];
    }
}
int main() {
    cin>>n;
    for(int i=0; i<n-1; i++) {
        int p, c; cin>>p>>c;
        v[p].push_back(c);
    }
    for(int i=0; i<n; i++){
        int w, b; cin>>w>>b;
        wb[i][0] = w;
        wb[i][1] = b;
    }
    solve(0);
    cout<<min(dp[0][0], dp[0][1]);


}