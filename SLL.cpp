#include <iostream>
#include <cmath>
using namespace std;
int arr[6], ans, remain;
int main(){
    for(int i=0; i<6; i++) cin>>arr[i];
    ans += (arr[4]*5 + arr[3]*4)/6;
    (ans%6 == 0) ? ans += 0 : ans += 1;
    remain = 6 * ans - (arr[4]*5 + arr[3]*4);
    arr[0] -= arr[4]*5; arr[1] -= arr[3]*2;
    if(remain >= 3){
        arr[2] -= 2;
        remain -= 3;
    }
    if(remain >= 2){
        arr[1] -= 3;
        remain -= 2;
    }
    if(remain >= 1){
        arr[0] -= 6;
        remain -= 1;
    }
    




}

