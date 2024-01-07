#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int K, M, prime[100001], checksum[100001], checkpro[100001];
vector<long long>prime_v;
vector<int>ans;
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
void checkCondition(){
    for(int i=0; i<prime_v.size(); i++)
        for(int j=i; j<prime_v.size(); j++){
            if(i == j){
                if(prime_v[i]*prime_v[j] > pow(10, K)) continue;
                checkpro[prime_v[i]*prime_v[j]] = 1;
            }else{
                if(prime_v[i]+prime_v[j] < pow(10, K))
                    checksum[prime_v[i]+prime_v[j]] = 1;
                if(prime_v[i]*prime_v[j] < pow(10, K)) 
                    checkpro[prime_v[i]*prime_v[j]] = 1;
            }
        }
    for(int i=pow(10, K-1); i< pow(10, K); i++){
        if(checksum[i] == 0 || checkpro[i] ==0) continue;
        if(i%M == 0) continue;
        ans.push_back(i);
        long long check = i;
        while(check < pow(10, K)){
            check *= M;
            if(check >= pow(10, K)) break;
            if(checksum[check] && checkpro[check]){
                checksum[check] = 0;
                ans.push_back(check);
                continue;
            }
            break;
        }
    }
}
int checkans(){
    int check = 0;
    for(auto e : ans){
        string s = to_string(e);
        int addi = 1;
        if(s.size() < K) continue;
        int arr[10]={0};
        for(auto e : s)
            arr[e-'0'] += 1;
        for(int i=0; i<10; i++)
            if(arr[i] >= 2) addi = 0;
        check += addi;

    }
    return check;
}

int main(){
    cin>>K>>M;
    calPrimeNumber();
    checkCondition();
    cout<<checkans();
}