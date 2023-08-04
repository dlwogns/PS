#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int T, n, check=0;
void permu(int c, int* ans, int* arr){
    if(n+1 == c){
        for(int i=1; i<=n; i++)
            cout<<ans[i]<<' ';
        cout<<endl;
        check = 1;
        return;
    }
    for(int i=1; i<=n; i++){
        if(arr[i]) continue;
        if(c == i) continue;
        arr[i] = 1;
        ans[c] = i;
        if(c>1)
            if(abs(ans[c-2]-ans[c-1]) != 1 && abs(ans[c]-ans[c-1]) != 1){
                arr[i] = 0;
                ans[c] = 0;
                continue;
            }
        if(c == n)
            if(abs(ans[c] - ans[c-1]) != 1){
                arr[i] = 0;
                ans[c] = 0;
                continue;
            }
        permu(c+1, ans, arr);
        if(check) return;
        arr[i] = 0;
        ans[c] = 0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        int ans[200001]={0};
        int arr[200001]={0};
        cin>>n;
        permu(1, ans, arr);
        if(check == 0)  cout<<-1<<'\n';
        check = 0;
    }
}
