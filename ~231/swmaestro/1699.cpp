#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int N, arr[100001];
vector<int>v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++)
        arr[i] = i;
    for(int i=2; i<=N; i++)
        for(int j=2; j*j<=i; j++){
            arr[i] = min(arr[i], arr[i-j*j]+1);
        }
    cout<<arr[N];
}