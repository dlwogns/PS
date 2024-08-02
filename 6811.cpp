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
int fish[4], ans;
int main() {
    for(int i=0; i<4; i++) 
        cin>>fish[i];
    for(int i=0; i<=100; i++)
        for(int j=0; j<=100; j++)
            for(int k=0; k<=100; k++) {
                if(!(i||j||k)) continue;
                if(i*fish[0]+j*fish[1]+k*fish[2]<=fish[3]){
                    cout<<to_string(i)+" Brown Trout, "+to_string(j)+" Northern Pike, "+to_string(k)+" Yellow Pickerel\n";
                    ans += 1;
                }
            }
    cout<<"Number of ways to catch fish: "+to_string(ans);
    
}