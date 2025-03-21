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
int main() {
    cin>>T;
    while(T--) {
        ll n, k; cin>>n>>k;
        ll arr[200002]={0};
        for(int i=1; i<=n; i++) arr[i] = i;
        ll max_s = 0;
        for(int i=1; i<=n; i++) {
            max_s += abs(arr[i] - arr[n-i+1]);
        }
        if(k > max_s || k%2 == 1) {
            cout<<"NO\n";
        } 
        else {
            int lo = 1, hi = n;
            while(lo < hi) {
                if(k >= abs(arr[lo] - arr[hi]) * 2) {
                    k -= abs(arr[lo] - arr[hi]) * 2;
                    swap(arr[lo], arr[hi]);
                    lo++;
                    hi--;
                } else {
                    hi --;
                }
            }
            cout<<"YES\n";
            for(int i=1; i<=n; i++) cout<<arr[i]<<" ";
            cout<<'\n';
        }
    }
}
