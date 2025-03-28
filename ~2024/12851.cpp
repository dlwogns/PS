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
int arr[3000001];
int main() {
    int a; cin>>a;
    for(int i=0; i<=3000000; i++) arr[i] = INT_MAX;
    arr[1] = 0;
    for(int i=1; i<=1000001; i++) {
        arr[i+1] = min(arr[i]+1, arr[i+1]);
        arr[i*2] = min(arr[i]+1, arr[i*2]);
        arr[i*3] = min(arr[i]+1, arr[i*3]);
    }
    cout<<arr[a]<<'\n';
    for(int i=1; i<=100; i++) cout<<i<<"idx: "<<arr[i]<<endl;
    while(a) {

        if(a == 1) {
            cout<<a; break;
        }
        if(arr[a] -1 == arr[a-1]){
            cout<<a<<' ';
            a -= 1;
        }else if(arr[a] -1 ==  arr[a/2] && a%2 == 0) {
            cout<<a<<' ';
            a /= 2;
        }else if(arr[a] - 1 == arr[a/3] && a%3 == 0) {
            cout<<a<<' ';
            a /= 3;
        }
    }

}