#include <iostream>
#include <cmath>
using namespace std;
int Q, L, R, arr[500001];
int primeNum[1000001], num;
void PrimeNumberSieve(){
    for(int i=2; i<=1000000; i++) primeNum[i] = i;
    for(int i=2; i<= sqrt(1000000); i++){
        if(!primeNum[i]) continue;
        for(int j= i*i; j<=1000000; j += i) primeNum[j] = 0;
        // i*k(k<i) 까지는 이미 검사했으므로, i*i부터 검사한다.
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>Q;
    PrimeNumberSieve();
    for(int i=3; i<=500000; i++){
        if(primeNum[i+i-1]) arr[i] = arr[i-1] + 1;
        else arr[i] = arr[i-1];
    }
    while(Q--){
        cin>>L>>R;
        cout<<arr[R] - arr[L]<<'\n';
    }

}