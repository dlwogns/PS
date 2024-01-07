#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int prime_check[1000001], T;
vector<int>prime;
void prime_seive(){
    for(int i=0; i<=1000000; i++) prime_check[i] = i;
    for(int i=2; i<=sqrt(1000000); i++){
        if(!prime_check[i]) continue;
        for(int j = i*i; j<=1000000; j += i)
            prime_check[j] = 0;
    }
    for(int i=2; i<=1000000; i++)
        if(prime_check[i] != 0)
            prime.push_back(i);
}
int main(){
    prime_seive();
    cin>>T;
    while(T--){
        int n; cin>>n;
        cout<<prime[prime[n-1]-1]<<'\n';
    }
}