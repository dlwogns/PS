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
string binarystr(int n) {
    string ret = "";
    if(n == 0) return "0";
    while(n>0) {
        ret += (n%2) + '0';
        n/=2;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--) {
        ll a, b; cin>>a>>b;
        ll a2 = max(a, b); ll b2 = min(a, b);
        string as = binarystr(a2);
        string bs = binarystr(b2);
        while(as.size() != bs.size()) bs.push_back('0');
        ll ans = 0, chk=0;
        for(int i=0; i<as.size(); i++) {
            if(as[i] == bs[i]) {
                chk += 1;
            }else  {
                break;
            }
        }
        ans = max(ans, chk);
        unsigned long long ansnum = 1;
        for(int i=0; i<ans; i++) ansnum *= 2;
        cout<<ansnum<<'\n';
    }
}
 