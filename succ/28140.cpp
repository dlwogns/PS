#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int N, Q;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N>>Q;
    cin>>s;
    vector<int>red;
    vector<int>blue;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'R') red.push_back(i);
        if(s[i] == 'B') blue.push_back(i);
    }
    while(Q--){
        int l, r;
        cin>>l>>r;
        if(red.size() <= 1 || blue.size() <= 1){
            cout<<-1<<'\n';
            continue;
        }
        int ridx = lower_bound(red.begin(), red.end(), l) - red.begin();
         if(ridx == red.size()-1 || red[ridx] < l){
            cout<<-1<<'\n';
            continue;
        }
        if(red[ridx] >= red[ridx+1]){
            cout<<-1<<'\n';
            continue;
        }
        int bidx = upper_bound(blue.begin(), blue.end(), red[ridx+1]) - blue.begin();
         if(bidx == blue.size()-1 || blue[bidx] <= red[ridx+1]){
            cout<<-1<<'\n';
            continue;
        }
        if(blue[bidx+1] > r || blue[bidx] >= blue[bidx+1]){
            cout<<-1<<'\n';
            continue;
        }
        cout<<red[ridx]<<' '<<red[ridx+1]<<' '<<blue[bidx]<<' '<<blue[bidx+1]<<'\n';
    }


}