#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int N, x, ans;
int arr[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>arr[i];
    cin>>x;
    sort(arr, arr+N);
    for(int i=0; i<N; i++){
        if(x == arr[i]*2 || x < arr[i]) continue;
        int st = 0, dest = N-1;
        while(st <= dest){
            int mid = (st+dest)/2;
            if(arr[mid] + arr[i] == x){
                ans += 1;
                break;
            }
            if(arr[mid] > x - arr[i])
                dest = mid - 1;
            else if(arr[mid] < x - arr[i])
                st = mid + 1;
        }
    }
    cout<<ans/2;

}