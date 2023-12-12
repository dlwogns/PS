#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[1000001], ans1, ans2;
int main(){
    cin>>N;
    for(int i=1; i<=N; i++) cin>>arr[i];
    for(int i=1; i<=N-1; i++){
        if(arr[i] > arr[i+1]) (!ans1) ? ans1 = i : ans1 = -1;
        if(arr[i] < arr[i+1]) (!ans2) ? ans2 = i : ans2 = -1;
    }
    if(ans1 != 0 && arr[N] > arr[1]) ans1 = -1;
    if(ans2 != 0 && arr[N] < arr[1]) ans2 = -1;

    if(ans1 == -1 && ans2 == -1) cout<<-1;
    else if(ans1 == -1 ) cout<<ans2;
    else if(ans2 == -1) cout<<ans1;
    else cout<<min(ans1, ans2);


}