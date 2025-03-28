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
        int N; cin>>N;
        int chk = 0;
        for(int i=0; i<N; i++) {
            if(i == N-1) {
                int a; cin>>a;
                cout<<a+chk<<'\n';
                break;
            }
            int a; cin>>a;
            chk = max(chk, a);

        }
    }
}