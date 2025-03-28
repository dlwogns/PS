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
int N, M, arr[1001][1001], ans[1001][1001];
int main() {
    cin>>N>>M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            cin>>arr[i][j];
    for(int i=1; i<=N; i++) 
        for(int j=1; j<=M; j++){
            if(ans[i][j-1] > ans[i-1][j]) ans[i][j] = ans[i][j-1] + arr[i][j];
            else ans[i][j] = ans[i-1][j] + arr[i][j];
            if(j == M) cout<<ans[i][j]<<'\n';
        }
    

}

// 1 2 3
// 3 2 1

// 3 1
// 7 14
// 9