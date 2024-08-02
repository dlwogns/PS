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

using namespace std;
int N, h, v;

int main() {
    cin>>N>>h>>v;
    cout<<max(max(max(h*v, (N-h)*v), h*(N-v)), (N-h)*(N-v))*4;
}