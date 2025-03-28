#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int K, M, prime[100001], psum[200001];
vector<long long>prime_v;
int ans;
void calPrimeNumber(){
    for(int i=2; i<pow(10, K); i++) prime[i] = i;
    for(int i=2; i<= sqrt(pow(10, K)); i++){
        if(!prime[i]) continue;
        for(int j=i*i; j< pow(10, K); j += i) prime[j] = 0;
    }
    for(int i=2; i< pow(10, K); i++)
        if(prime[i]){
            prime_v.push_back(i);
        }
}

int main(){
    cin>>K>>M;
    calPrimeNumber();
    int pk = pow(10, K);
    for(int i=0; i<prime_v.size(); i++)
        for(int j=i+1; j<prime_v.size(); j++)
            if(prime_v[i]+prime_v[j] < pk)
                psum[prime_v[i]+prime_v[j]] = 1;
    for(int i=0; i<prime_v.size(); i++)
        for(int j=i; j<prime_v.size(); j++) {
            
        }
    cout<<ans;
}