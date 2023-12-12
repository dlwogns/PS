#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string board[9];
vector<pair<int,int>>v;
void func(int n){
    if(n == v.size()){
        for(int i=0; i<9; i++)
            cout<<board[i]<<'\n';
        exit(0);
    }
    pair<int,int>point = v[n];
    int arr[11]={0};
    for(int i=0; i<9; i++){
        arr[board[point.first][i]-'0'] = 1;
        arr[board[i][point.second]-'0'] = 1;
    }
    for(int i = (point.first/3)*3; i<(point.first/3)*3+3; i++)
        for(int j = (point.second/3)*3; j<(point.second/3)*3+3; j++)
            arr[board[i][j]-'0'] = 1;
    for(int i=1; i<=9; i++){
        if(arr[i]) continue;
        board[point.first][point.second] = i+'0';
        func(n+1);
        board[point.first][point.second] = '0';
    }
}

int main(){
    for(int i=0; i<9; i++){
        cin>>board[i];
    }
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(board[i][j] == '0')
                v.push_back({i,j});
    func(0);

}