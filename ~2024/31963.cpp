#include <iostream>
#define ll int 
using namespace std;
ll N, ans, pow_arr[50];
int main() {
    cin>>N; ll* arr = new ll[N];
    for(int i=0; i<N; i++)
        cin>>arr[i];
    pow_arr[0] = 1;
    pow_arr[1] = 2;
    for(int i=2; i<50; i++) {
        pow_arr[i] = pow_arr[i-1]*2;
    }
    for(int i=1; i<N; i++) {
        if(arr[i] < arr[i-1]) {
            int l=0, r=49;
            while(l+1<r) {
                int mid = (l+r)/2;
                if(arr[i]*pow_arr[mid] >= arr[i-1]){
                    r = mid;
                }else
                    l = mid;
            }
            arr[i] = arr[i]*pow_arr[r];
            ans += r;
        }
    }
    cout<<ans;
}