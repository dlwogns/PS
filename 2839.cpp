#include <iostream>
#include <vector>
#define INTMAX 987654321
using namespace std;
int N;
vector<long long>v(5001, INTMAX);
int main(){
    cin>>N;
    v[3] = 1; v[5] = 1;
    for(int i=6; i<=N; i++)
        v[i] = min(v[i-3]+1, v[i-5]+1);
    if(v[N] >= INTMAX)  cout<<-1;
    else cout<<v[N];
}