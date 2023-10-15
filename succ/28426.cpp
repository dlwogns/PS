#include <iostream>
#include <vector>
using namespace std;
long long N;
int main(){
    cin>>N;
    long long ans = 5;
    vector<long long>v;
    v.push_back(3);
    v.push_back(2);
    for(int i=2; i<=500000; i++){
        if(v.size() == N) break;
        if((ans+i*2)%3 == 0){
            ans += i*2;
            v.push_back(i*2);
        }
    }
    if(N == 1)
        cout<<3;
    else if(N == 2)
        cout<<3<<' '<<6;
    else{
        for(auto e : v)
            cout<<e<<' ';
    }
}