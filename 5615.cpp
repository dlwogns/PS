#include <iostream>
using namespace std;
#define ll unsigned long long 
ll N, ans;
int a_param[5] = {2, 3, 5, 7, 11};
ll power(ll x, ll y, ll mod) {
    ll result = 1;
    x %= mod;
    while(y) {
        if(y%2) result = (result*x)%mod;
        y/=2;
        x = (x*x)%mod;
    }
    return result;
}
bool miller(ll n, ll a) {
    if(a%n == 0) return false;
    ll k = n-1;
    while(1) {
        ll temp = power(a, k, n);
        if(temp == n-1) return true;
        if(k%2) return (temp == 1 || temp == -1);
        k /= 2;
    }
}

int isPrime(ll n) {
    if(n == 2 || n == 3) return true;
    if(n%2 == 0 || n == 1) return false;
    for(int i=0; i<5; i++) {
        ll a = a_param[i];
        if(a == n) return true;
        if(!miller(n, a)) return false;
    }
    return true;
}

int main() {
    cin>>N;
    while(N--) {
        ll S; cin>>S;
        if(isPrime(2*S+1)) ans += 1;
    }
    cout<<ans;
}