#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, ans=987654321;
vector<pair<int,int > > v;
int board[9][9], vis[9][9];
void camera(int n, int m , int dir, int x){
    if(dir == 0){
        while(n>=0 && board[n][m] != 6){
            vis[n][m] += x;
            n -= 1;
        }
    }else if(dir == 1){
        while(m<M && board[n][m] != 6){
            vis[n][m] += x;
            m += 1;
        }
    }else if(dir == 2){
        while(n<N && board[n][m] != 6){
            vis[n][m] += x;
            n += 1;
        }
    }else{
        while(m>=0 && board[n][m] != 6){
            vis[n][m] += x;
            m -= 1;
        }
    }
}
void func(int idx){
    if(idx == v.size()){
        int check = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                if(vis[i][j] == 0 && board[i][j] == 0) check += 1;
        ans = min(check, ans);
        return;
    }
    int n = v[idx].first, m = v[idx].second, c = board[n][m];
    if(c == 1){
        for(int i=0; i<=3; i++){
            camera(n, m, i, 1);
            func(idx+1);
            camera(n,m,i,-1);
        }
    }else if(c == 2){
        for(int i=0; i<=1; i++){
            camera(n,m,i,1);
            camera(n,m,i+2,1);
            func(idx+1);
            camera(n,m,i,-1);
            camera(n,m,i+2,-1);

        }
    }else if(c == 3){
        for(int i=0; i<=3; i++){
            camera(n,m,i,1);
            camera(n,m,(i+1)%4, 1);
            func(idx+1);
            camera(n,m,i,-1);
            camera(n,m,(i+1)%4, -1);
        }
    }else if(c == 4){
        for(int i=0; i<=3; i++){
            camera(n,m,i,1);
            camera(n,m,(i+1)%4, 1);
            camera(n,m,(i+2)%4, 1);
            func(idx+1);
            camera(n,m,i,-1);
            camera(n,m,(i+1)%4, -1);
            camera(n,m,(i+2)%4, -1);
        }
    }else{
        for(int i=0; i<=3; i++)
            camera(n,m,i,1);
        func(idx+1);
        for(int i=0; i<=3; i++)
            camera(n,m,i,-1);
    }

}
int main(){
    cin>>N>>M;
    
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            cin>>board[i][j];
            if(board[i][j] >= 1 && board[i][j]<=5)
                v.push_back(make_pair(i,j));
        }
    func(0);
    cout<<ans;
}