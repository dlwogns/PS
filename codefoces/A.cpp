#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int T;
int main(){
    cin>>T;
    while(T--){
        string board[8];
        char a = '.';
        for(int i=0; i<8; i++)
            cin>>board[i];
        for(int i=0; i<8; i++){
            if(board[i] == "RRRRRRRR" || board[i] == "BBBBBBBB"){
                a = board[i][0];
                break;
            }
        }
        for(int i=0; i<8; i++){
            int R = 0, B = 0;
            for(int j=0; j<8; j++){
                if(board[j][i] == 'R') R += 1;
                else if(board[j][i] == 'B') B += 1;
                if(R == 8) a = 'R';
                else if(B == 8) a = 'B';
            }
        }
        cout<<a<<'\n';
    }

}