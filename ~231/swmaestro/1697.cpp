#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int N, K;
vector<int>v(100001, INF);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N>>K;
    v[N] = 0;
    if(N > K){
        v[K] = N-K;
    }else{
        queue<int>q;
        q.push(N);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur == K) break;
            if(cur < 100000 && v[cur+1] > v[cur] + 1){
                v[cur+1] = v[cur]+1;
                q.push(cur+1);
            }
            if(cur > 0 && v[cur-1] > v[cur]+1){
                v[cur-1] = v[cur]+1;
                q.push(cur-1);
            }
            if(cur * 2 <= 100000 && cur != 0 && v[cur*2] > v[cur]+1){
                v[cur*2] = v[cur]+1;
                q.push(cur*2);
            }
        }
    }
    cout<<v[K];

}