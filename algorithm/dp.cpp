#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define INF 987654321
int N;
int main(){
    cin>>N;
    vector<int>v(3000001, INF);
    v[1] = 0;
    for(int i=1; i<=N; i++){
        v[i+1] = min(v[i+1], v[i]+1); 
        v[i*2] = min(v[i*2], v[i]+1);
        v[i*3] = min(v[i*3], v[i]+1);
    }

    cout<<v[N];
}