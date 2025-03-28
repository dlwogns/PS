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
int T;
ll solve(ll k, ll a, ll b, ll n) {
    return a * (n-k) + (b+1) * k - k * (k+1) / 2;
}
int main() {
    cin>>T;
    while(T--) {
        ll n, a, b; cin>>n>>a>>b;
        ll cnum = min(n, b);
        ll chk = max((2*b-2*a+1)/2, 0ll);
        cout<<solve(min(chk, cnum), a, b, n)<<'\n';
    }
}