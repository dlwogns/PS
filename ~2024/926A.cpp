#include <iostream>
#include <algorithm>
using namespace std;
int T;
int main(){
    cin>>T;
    while(T--){
        int arr[501], n;
        long long ans = 0;
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>arr[i];
        sort(arr, arr+n);
        for(int i=1; i<n; i++)
            ans += arr[i]-arr[i-1];
        cout<<ans<<'\n';
    }
}

// 5분