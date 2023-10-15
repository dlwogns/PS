// 에라토스테네스의 체 코드
// NloglogN
#include <iostream>
#include <cmath>
using namespace std;
int primeNum[100001], num;
void PrimeNumberSieve(){
    for(int i=2; i<=100000; i++) primeNum[i] = i;
    for(int i=2; i<= sqrt(100000); i++){
        if(!primeNum[i]) continue;
        for(int j= i*i; j<=100000; j += i) primeNum[j] = 0;
        // i*k(k<i) 까지는 이미 검사했으므로, i*i부터 검사한다.
    }
    for(int i=2; i<=num; i++)
        if(primeNum[i] != 0) cout<<i<<' ';

}
int main(){
    cin>>num;
    PrimeNumberSieve();
}