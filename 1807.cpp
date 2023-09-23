#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int k;
    long long arr[16];
    for(int i=1; i<=15; i++)
        arr[i] = (pow(10, i) - pow(10, i-1))*(i+1) - (pow(10,i)/4 - pow(10, i-1)/4);
    
    while(cin>>k && k != 0){
        int check = 0;
        for(int i=1; i<=15; i++)
            if(arr[i] >= k){
                check = i; break;
            }
        long long lo = pow(10, check-1), hi = pow(10, check);
        while(lo+1 < hi){
            long long mid = (lo+hi)/2;
            long long digit=0;
            for(int i=1; i<check; i++)
                digit += arr[i];
            digit += (mid - pow(10, check-1)) * (check+1) - (mid/4 - pow(10, check-1)/4);
            if(digit <=k) lo = mid;
            else hi = mid;
        }
        cout<<lo<<' '<<hi<<endl;
    }
}

// 1220324526072892 100 112