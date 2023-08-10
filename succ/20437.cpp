#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int T;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        string s;
        int n, mans = 0, mians = 987654321, arr[26]={0};
        cin>>s;
        cin>>n;
        for(auto c : s)
            arr[c-'a'] += 1;
        for(int i=0; i<s.size(); i++){
            if(arr[s[i]-'a'] < n) continue;
            int cnt = 0;
            for(int j=i; j<s.size(); j++){
                if(s[j] == s[i]) cnt += 1;
                if(cnt == n){
                    mans = max(mans, j-i+1);
                    mians = min(mians, j-i+1);
                    break;
                }
            }
        }
        if(mans == 0 || mians == 987654321) cout<<-1<<'\n';
        else cout<<mians<<' '<<mans<<'\n';
    }
}