#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
struct question{
    int T, x, y;
    question(int a, int b, int c){
        T = a; x = b; y = c;
    }
    bool operator<(const question &q){
        return T < q.T;
    }
};
int N, M, K, Q, tomato[200001];
vector<vector<int>>v(200001);
vector<question>q;
int main(){
    fastio;
    cin>>N>>M>>K>>Q;
    for(int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0; i<N; i++) tomato[i] = -1;
    for(int i=0; i<K; i++){
        int X;
        cin>>X;
        tomato[X] = 0;
    }
    for(int i=0; i<Q; i++){
        int T, x, y;
        cin>>T>>x>>y;
        q.push_back(question(T, x, y));
    }
    sort(q.begin(), q.end());
    

}