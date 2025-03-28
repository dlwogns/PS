#include <iostream>
#include <vector>
using namespace std;
int T, n, arr[100001], check[100001], checknum;
bool func(int ori, int i, vector<int>& dis, vector<int>& x){
    if(check[i]){
        checknum = i;
        return false;
    }
    if(arr[i] == i || x[i]){
        x[i] = 1;
        return false;
    }
    if(arr[i] == ori)
        return true;
    check[i] = 1;
    if(func(ori, arr[i], dis, x)){
        dis[i] = 1;
        check[i] = 0;
        return true;
    }
    if(checknum){
        dis[i] = 1;
        check[i] = 0;
        if(i == checknum)
            checknum = 0;
        return false;
    }
    x[i] = 1;
    check[i] = 0;
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        vector<int>dis(100001, 0);
        vector<int>x(100001, 0);
        for(int i=1; i<=n; i++){
            cin>>arr[i];
            if(arr[i] == i) dis[i] = 1;
        }
        for(int i=1; i<=n; i++){
            if(dis[i] == 0 || x[i])
                func(i, i, dis, x);
        }
        int ans = 0;
        for(int i=1; i<=n; i++)
            if(dis[i] == 0) ans +=1;
        cout<<ans<<'\n';
    }
}