#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int N , board[1001][1001], ans;
vector<pair<int,int> >v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        int xpoint, height;
        cin>>xpoint>>height;
        v.push_back(make_pair(xpoint, height));
    }
    sort(v.begin(), v.end());
    //for(int i=0; i<v.size(); i++)
    int i = 0;
    while(i < v.size()){
        pair<int,int> cur = v[i];
        int check = 0;
        for(int y=0; y<cur.second; y++)
            board[cur.first][y] = 1;
        if(i == v.size()-1) break;
        for(int j=i+1; j<v.size(); j++){
            //현재보다 큰게 있는 경우
            if(v[j].second < cur.second) continue;
            else{
                for(int x = cur.first+1; x < v[j].first; x++)
                    for(int y=0; y<cur.second; y++)
                        board[x][y] = 1;
                i = j;
                check = 1;
                break;
            }
        }
        //현재보다 큰게 없는 경우
        if(check) continue;
        pair<int,int>ma = make_pair(0,0);
        int idx = 0;
        for(int j=i+1; j<v.size(); j++)
            if(v[j].second >= ma.second){
                ma = v[j];
                idx = j;
            }
        for(int x = cur.first+1; x<ma.first; x++)
            for(int y=0; y<ma.second; y++)
                board[x][y] = 1;
        i = idx;
    }
    // for(int i=0; i<20; i++){
    //     cout<<endl;
    //     for(int j=0; j<20; j++)
    //         cout<<board[i][j];
    // }
    for(int i=0; i<=1000; i++)
        for(int j=0; j<=1000; j++)
            if(board[i][j]) ans += 1;
    cout<<ans;
}