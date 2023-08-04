#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int N, ans;
vector<pair<int,pair<int,int> > >v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        int input, st, ba;
        cin>>input>>st>>ba;
        v.push_back(make_pair(input, make_pair(st, ba)));
    }
    for(int i=111; i<=999; i++){
        string s = to_string(i);
        int flag = 1;
        if(s[0] == '0' || s[1] == '0' || s[2] == '0') continue;
        if(s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) continue;
        for(auto e : v){
            string num = to_string(e.first);
            int strike = 0;
            int ball = 0;
            for(int i=0; i<=2; i++)
                if(s[i] == num[i])
                    strike += 1;
                else if(num[i] == s[(i+1)%3] || num[i] == s[(i+2)%3])
                    ball += 1;
            if(strike == e.second.first && ball == e.second.second)
                continue;
            flag = 0;
        }
        if(flag) ans += 1;
    }
    cout<<ans;
}