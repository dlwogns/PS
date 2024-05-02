#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int isPrime[1000001], isTime[1000001];
vector<int>priArr;
void pcheck() {
    for(int i=2; i <= 1000000; i++) isPrime[i] = i;
    for(int i=2; i*i <=1000000; i++) {
        if(!isPrime[i]) continue;
        for(int j = i*i; j<=1000000; j += i) isPrime[j] = 0;
    }
    for(int i=2; i<=1000000; i++)
        if(isPrime[i]) priArr.push_back(i);
}
int main() {
    ll a = 1, N;
    cin>>N;
    pcheck();
    for(auto e : priArr) {
        long long check = e;
        while(check * e <= 1000000){
            check = check * e;
            isTime[check] = e;
        }
    }
    for(int i=1; i<=N; i++){
        if(isPrime[i])
            a = (a*i)%987654321;
        else {
            if(isTime[i])
                a = (a*isTime[i])%987654321;
        }
    }
    cout<<a;
}