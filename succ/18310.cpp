#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int N, check[100001];
vector<int>v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        int input;
        cin>>input;
        if(check[input]) continue;
        check[input] = 1;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    
}