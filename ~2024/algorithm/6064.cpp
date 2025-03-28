#include <iostream>
using namespace std;
int T;
long long gcd(int a, int b){
    int r;
    while(b != 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
long long lcm(int a, int b){
    return (a*b)/gcd(a, b);
}
int main(){
    cin>>T;
    while(T--){
        long long M, N, x, y, ans = 0; cin>>M>>N>>x>>y;
        long long maxans = lcm(M, N);
        for(int i=x; i<=maxans; i+=M){
            int check = i%N;
            if(check == 0)
                check = N;
            if(check == y){
                ans = i;
                break;
            }
        }
        (ans) ? cout<<ans : cout<<-1;
        cout<<'\n';
    }
}