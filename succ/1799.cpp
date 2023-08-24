#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define vii vector<pair<int, int > >
using namespace std;
int N, checkboard[11][11], board[11][11], ans;
bool check(int x, int y, vii& bis){
    for(auto e : bis){
        if(e.first == x && e.second == y) continue;
        if(abs(e.first - x) == abs(e.second - y)) return false;
    }
    return true;
}
void func(int x, int y, vii& bis, int count){
    for(int i=x; i<N; i++)
        for(int j=y; j<N; j++){
            if(board[i][j]) continue;
            if(checkboard[i][j] == 0) continue;
            if(!check(i, j, bis)) continue;
            bis.push_back(make_pair(i, j));
            board[i][j] = 1;
            func(i, j, bis, count+1);
            bis.pop_back();
            board[i][j] = 0;
        }
    ans = max(ans, count);
    if(count == 4){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<board[i][j]<<' ';
            }
            cout<<endl;
        }
    }
}


int main(){
    fastio;
    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>checkboard[i][j];
    vii v;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(checkboard[i][j]){
                v.push_back(make_pair(i, j));
                board[i][j] = 1;
                func(i, j, v, 1);
                board[i][j] = 0;
            }
    cout<<ans;

}