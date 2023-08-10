#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int R, C, dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
string board[26];
int up(int x, int y){
    if(x >= R || x < 0 || y >= C || y < 0) return -1;
    if(board[x][y] == '|' || board[x][y] == '+' || board[x][y] == '1' || board[x][y] == '4') return 1;
    else if(board[x][y] == 'M' || board[x][y] == 'Z') return 2;
    return 0;
}
int down(int x, int y){
    if(x >= R || x < 0 || y >= C || y < 0) return -1;
    if(board[x][y] == '|' || board[x][y] == '+' || board[x][y] == '2' || board[x][y] == '3') return 1;
    else if(board[x][y] == 'M' || board[x][y] == 'Z') return 2;
    return 0;
}
int right(int x, int y){
    if(x >= R || x < 0 || y >= C || y < 0) return -1;
    if(board[x][y] == '-' || board[x][y] == '+' || board[x][y] == '3' || board[x][y] == '4') return 1;
    else if(board[x][y] == 'M' || board[x][y] == 'Z') return 2;
    return 0;
}
int left(int x, int y){
    if(x >= R || x < 0 || y >= C || y < 0) return -1;
    if(board[x][y] == '-' || board[x][y] == '+' || board[x][y] == '1' || board[x][y] == '2') return 1;
    else if(board[x][y] == 'M' || board[x][y] == 'Z') return 2;
    return 0;
}
int main(){
    cin>>R>>C;
    pair<int,int>cur={-1,-1};
    for(int i=0; i<R; i++)
        cin>>board[i];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++){
                if(cur.first != -1) break;
                if(board[i][j] == '.' || board[i][j]=='M' || board[i][j] == 'Z') continue;
                if(board[i][j] == '|'){
                    if(up(i-1, j) == 0) cur = {i-1, j};
                    if(down(i+1, j) == 0) cur = {i+1, j};
                }else if(board[i][j] == '-'){
                    if(right(i, j+1)== 0) cur = {i, j+1};
                    if(left(i, j-1)== 0) cur = {i, j-1};
                }else if(board[i][j]=='+'){
                    if(up(i-1, j) == 0) cur = {i-1, j};
                     if(down(i+1, j) == 0) cur = {i+1, j};
                    if(right(i, j+1)== 0) cur = {i, j+1};
                    if(left(i, j-1)== 0) cur = {i, j-1};
                }else if(board[i][j] == '1'){
                     if(down(i+1, j) == 0) cur = {i+1, j};
                     if(right(i, j+1)== 0) cur = {i, j+1};
                }else if(board[i][j] == '2'){
                    if(up(i-1, j) == 0) cur = {i-1, j};
                    if(right(i, j+1)== 0) cur = {i, j+1};
                }else if(board[i][j] == '3'){
                    if(up(i-1, j) == 0) cur = {i-1, j};
                    if(left(i, j-1)== 0) cur = {i, j-1};
                }else if(board[i][j] == '4'){
                     if(down(i+1, j) == 0) cur = {i+1, j};
                    if(left(i, j-1)== 0) cur = {i, j-1};
                }
        }
    char ans;
    int arr[4] = {up(cur.first - 1, cur.second), down(cur.first + 1, cur.second), right(cur.first, cur.second+1), left(cur.first, cur.second-1)};
    
    if(arr[0] >= 1&& arr[1] >= 1&& arr[2] >= 1&& arr[3] >= 1) ans = '+';
    else if(arr[0] >= 1&& arr[1] >= 1) ans = '|';
    else if(arr[2] >= 1&& arr[3] >= 1) ans = '-';
    else if(arr[0] >= 1&& arr[2] >= 1) ans = '2';
    else if(arr[0] >= 1&& arr[3] >= 1) ans = '3';
    else if(arr[1] >= 1&& arr[2] >= 1) ans = '1';
    else if(arr[1] >= 1&& arr[3] >= 1) ans = '4';
    
    
    if(arr[0] == 1&& arr[1] == 1&& arr[2] == 1&& arr[3] == 1) ans = '+';
    else if(arr[0] == 1&& arr[1] == 1) ans = '|';
    else if(arr[2] == 1&& arr[3] == 1) ans = '-';
    else if(arr[0] == 1&& arr[2] == 1) ans = '2';
    else if(arr[0] == 1&& arr[3] == 1) ans = '3';
    else if(arr[1] == 1&& arr[2] == 1) ans = '1';
    else if(arr[1] == 1&& arr[3] == 1) ans = '4';
    cout<<cur.first+1<<' '<<cur.second+1<<' '<<ans;
}