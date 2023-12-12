#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int N, L, arr[1001], check[1001], ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N>>L;
    for(int i=0; i<N; i++)
        cin>>arr[i];
    sort(arr, arr+N);
    for(int i=0; i<N; i++){
        if(check[i]) continue;
        int st = i, dest = N-1;
        while(st <= dest){
            if(arr[dest] - arr[st] < L){
                ans += 1;
                for(int j = st; j <= dest; j++)
                    check[j] = 1;
                break;
            }
            dest -= 1;
        }
    }
    cout<<ans;

}