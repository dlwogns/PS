#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
vector<int>v;
int ans[301][2];
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        int input;
        cin>>input;
        v.push_back(input);
    }
    // 0->다음꺼 밟ㅏㅗ 됨  1-> 안됨
    ans[1][0] = v[0];
    for(int i=2; i<=N; i++){
        ans[i][0] = max(ans[i-2][0], ans[i-2][1]) + v[i-1];
        ans[i][1] = max(ans[i-1][0] + v[i-1], ans[i][1]);
    }
    cout<<max(ans[N][0], ans[N][1]);
    
}