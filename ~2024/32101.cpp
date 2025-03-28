#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
char board[2003][2003];
int main() {
    cin>>n>>m;
    int R, G, B; cin>>R>>G>>B;
    vector<pair<int, char > >v;
    v.push_back(make_pair(R, 'R'));
    v.push_back(make_pair(G, 'G'));
    v.push_back(make_pair(B, 'B'));
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for(int c=0; c<3; c++) {
        char cur_c = v[c].second;
        int cur_cnt = v[c].first;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++) {
                if(cur_cnt == 0) continue;
                if(board[i][j] != 0) continue;
                if(board[i-1][j] == cur_c) continue;
                if(board[i][j-1] == cur_c) continue;
                board[i][j] = cur_c;
                cur_cnt -= 1;
            }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) {
            cout<<board[i][j];
        }
        cout<<'\n';
    }


}