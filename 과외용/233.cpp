#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long S, T, D, ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>S>>T>>D;
    vector<long long>sum(D, 0);
    for(int i=0; i<D; i++){
        long long w; cin>>w;
        if(i == 0) sum[i] = w;
        else sum[i] = w + sum[i-1];
    }
    for(int i=0; i<D; i++)
        if(T >= S + sum[i]){
            cout<<i+1;
            return 0;
        }
    if(sum[D-1] >= 0){
        cout<<-1; return 0;
    }
    long long comp = (T-S)%sum[D-1];
    if(comp == 0){
        cout<<(T-S)/sum[D-1]*D;
        return 0;
    }
    for(int i=0; i<D; i++)
        if(sum[i] <= comp){
            cout<<((T-S)/sum[D-1]*D) + (i+1);
            return 0;
        }
    cout<<-1;
}