#include <iostream>
#include <string>
using namespace std;
int N, M, K, board[50][50], vis[50];
string input[50];
void func(int l, int n, int k){
    if(k == n){
        
    }
    for(int i=l; i<M; i++){
        if(vis[i]) continue;
        vis[i] = 1;
        func(i, n, k+1);
        vis[i] = 0;
    }
}


int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++)
        cin>>input[i];
    for(int i=0; i<N; i++)
        for(int j=0; j<input[i].size(); j++)
            board[i][j] = input[i][j] - '0';
    
}