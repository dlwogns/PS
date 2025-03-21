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
int arr1[200001][26], arr2[200001][26];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--) {
       int n, q, ans=0; cin>>n>>q;
       string a, b; cin>>a>>b;
       for(int i=1; i<=n; i++){
            for(int j=0; j<26; j++) {
                arr1[i][j] = arr1[i-1][j];
                arr2[i][j] = arr2[i-1][j];
                if(a[i-1]-'a' == j) arr1[i][j] += 1;
                if(b[i-1]-'a' == j) arr2[i][j] += 1;
            }
       }
       while(q--) {
            int l, r; cin>>l>>r;
            for(int i=0; i<26; i++){
                ans += abs((arr1[r][i] - arr1[l-1][i]) - (arr2[r][i] - arr2[l-1][i]));
            }
            cout<<ans/2<<'\n';
            ans = 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<26; j++) {
                arr1[i][j] = 0;
                arr2[i][j] = 0;              
            }
       }
    }
}