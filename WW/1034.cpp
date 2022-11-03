#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, M, K, vis[50], ans;
string board[50];
int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++)
        cin>>board[i];
    cin>>K;
    for(int i=0; i<N; i++){
        if(vis[i]) continue;
        int zero_num=0, check_ans=0;
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j]=='0') zero_num += 1;
        }
        if(zero_num%2 != K%2) continue;
        if(K < zero_num) continue;
        for(int k=i; k<N; k++){
            if(board[k] == board[i]){
                check_ans += 1;
                vis[k] = 1;
            }
        }
        ans = max(ans, check_ans);
    }
    cout<<ans;
}