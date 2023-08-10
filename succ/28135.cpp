#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int N, arr[1000001], ans;
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        if(arr[i] <= arr[i-1]) ans += 1;
    }
    if(arr[N-1] >= arr[0]) ans += 1;
    cout<<ans;
}