#include <iostream>
#define INF 987654321
using namespace std;
int DP[100001][5][5], ans=INF;
int main(){
    int input;
    int idx=0;
    for(int i=0; i<=100000; i++)
        for(int j=0; j<5; j++)
            for(int k=0; k<5; k++)
                DP[i][j][k] = INF;
    while(cin>>input){
        if(input == 0) break;
        idx += 1;
        if(idx == 1){
            DP[idx][input][0] = 2;
            DP[idx][0][input] = 2;
            continue;
        }
        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++){
                if(DP[idx-1][i][j] != INF){
                    cout<<i<<' '<<j<<endl;
                    if(i == input)
                        DP[idx][input][j] = min(DP[idx][input][j], DP[idx-1][i][j]+1);
                    else if(i == 0)
                        DP[idx][input][j] = min(DP[idx][input][j], DP[idx-1][i][j]+2);
                    else if(i%2 == input%2)
                        DP[idx][input][j] = min(DP[idx][input][j], DP[idx-1][i][j]+4);
                    else
                        DP[idx][input][j] = min(DP[idx][input][j], DP[idx-1][i][j]+3);
                    if(j == input)
                        DP[idx][i][input] = min(DP[idx][i][input], DP[idx-1][i][j]+1);
                    else if(j == 0)
                        DP[idx][i][input] = min(DP[idx][i][input], DP[idx-1][i][j]+2);
                    else if(j%2 == input%2)
                        DP[idx][i][input] = min(DP[idx][i][input], DP[idx-1][i][j]+4);
                    else
                        DP[idx][i][input] = min(DP[idx][i][input], DP[idx-1][i][j]+3);
                }
            }

    }
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            ans = min(ans, DP[idx][i][j]);
    cout<<ans;
}