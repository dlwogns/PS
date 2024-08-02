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
    for_N(T){
        int N, B=0, W=0; cin>>N;
        string s1, s2; cin>>s1>>s2;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]) {
                if(s1[i] == 'B') B +=1;
                else W += 1;
            }
        }
        cout<<min(B, W) + max(B, W) - min(B, W)<<'\n';
    }
}