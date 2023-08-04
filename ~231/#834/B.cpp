#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int main(){
    cin>>T;
    while(T--){
        int m, s, arr[51]={0}, ans=1, check = 0, check2 = 1;
        cin>>m>>s;
        for(int i=0; i<m; i++){
            int input;
            cin>>input;
            arr[input] = 1;
        }
        for(int i=1; i<=50; i++){
            if(s <= 0) break;
            if(arr[i] == 1) continue;
            if(s - i < 0) break;
            s -= i;
            arr[i] = 1;
            check = 1;
        }
        vector<int>v;
        for(int i=1; i<=50; i++){
            if(arr[i] == 1) v.push_back(i);
        }
        sort(v.begin(), v.end());
        for(int i=1; i<=50; i++){
            if(i <= v.size() && v[i-1] == i) continue;
            else check2 = 0;
        }
        if(ans && s == 0 && check && check2) cout<<"YES\n";
        else cout<<"NO\n";
    }
}