#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define INTMAX 987654321
using namespace std;
int W, H, vis[101][101], dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}, ans[101][101];
vector<pair<int,int > > C;
string board[101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>W>>H;
    for(int i=0; i<H; i++)
        cin>>board[i];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++)
            if(board[i][j] == 'C'){
                C.push_back(make_pair(i,j));
            }
    }
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            ans[i][j] = INTMAX;


}