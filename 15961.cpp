#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N, d, k, c, ans;
int arr[3000001];
unordered_map<int, int> check;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>d>>k>>c;
    for(int i=0; i<N; i++)
        cin>>arr[i];
    int st= 0, dest = k-1;
    for(int i = st; i<= dest; i++){
        check[arr[i]] += 1;
    }
    //cout<<check.size()<<endl;
    ans = check.size();
    for(int i=1; i<N; i++){
        check[arr[i-1]] -= 1;
        if(check[arr[i-1]] == 0)
            check.erase(arr[i-1]);
        dest = (dest+1)%N;
        check[arr[dest]] += 1;
        if(check.find(c) == check.end()){
            ans = max(int(check.size())+1, ans);
        }else
            ans = max(int(check.size()), ans);
    }
    cout<<ans;
}