#include <iostream>
#include <string>
using namespace std;
string s, t;
int dp[3001][3001];
void func(int x, int y){
    if(x == 0 || y == 0)
        return;
    if(dp[x-1][y-1] == dp[x][y]-1 && s[x-1] == t[y-1]){
        func(x-1, y-1);
        cout<<s[x-1];
        return;
    }
    if(dp[x][y-1] == dp[x][y]){
        func(x, y-1);
    }else if(dp[x-1][y] == dp[x][y]){
        func(x-1, y);
    }
}
int main(){
    cin>>s>>t;
    for(int i=1; i<=s.size(); i++)
        for(int j=1; j<=t.size(); j++){
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    func(s.size(), t.size());
}