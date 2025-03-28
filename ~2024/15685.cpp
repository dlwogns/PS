#include <iostream>
#include <vector>
using namespace std;
int N, board[101][101], ans;
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        int x, y, d, g; cin>>x>>y>>d>>g;
        board[y][x] = 1;
        vector<int>v;
        v.push_back(d);
        while(g--){
            int orivsize = v.size()-1;
            for(int i=orivsize; i>=0; i--){
                v.push_back((v[i]+1)%4);
            }
        }
        for(int i=0; i<=v.size()-1; i++){
            if(v[i] == 0){
                board[y][x+1] = 1;
                x = x+1;
            }else if(v[i] == 1){
                board[y-1][x] = 1;
                y = y-1;
            }else if(v[i] == 2){
                board[y][x-1] = 1;
                x = x-1;
            }else if(v[i] == 3){
                board[y+1][x] = 1;
                y = y+1;
            }
        }
    }
    
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++){
            if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1])
                ans += 1;
        }
    cout<<ans;
}