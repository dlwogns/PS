#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<deque<int> > v(1001);
int N, girls[1001][1001], matched[1001], check[1001];
// matched -> i번쨰 남자가 어떤 여자랑 짝인지 체크
// check -> i번째 여자가 어떤 남자랑 짝인지 체크
int main() {
    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            int pri; cin>>pri;
            v[i+1].push_back(pri);
        }
        // 남자 -> 여자 로 짝을 맞추기 때문에 
        // 남자를 기준으로 우선순위가 높은 여자부터 짝을 짓기 때문에 
        // 인접 리스트로 생성
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            int pri; cin>>pri;
            girls[i+1][pri] = N-j;
            // 우선순위에 해당하는 숫자가 높을수록 우선순위가 높음.
        }
        // 여자가 이미 짝이 있을때 새로운 고백을 받았을떄 이전의 짝보다 우선순위가 높은지 확인해야 하기 때문에
        // 인접행렬로 상수시간에 접근할 수 있게 확인 
    
    // logic
    queue<int> q;
    for(int i=1; i<=N; i++)
        q.push(i);
    // 남자/여자 이분그래프 상의 탐색을 생각
    while(!q.empty()){
        // 처음에는 1~N까지의 모든 남자를 queue에 넣고
        // 그 후에는 짝이 지어졌다 깨진 경우 재탐색.
        int cur = q.front(); q.pop();
        while(!v[cur].empty()){
            int pri_girl = v[cur].front(); v[cur].pop_front();
            // 기존의 짝이 우선순위가 더 높은 경우
            if(girls[pri_girl][cur] < girls[pri_girl][check[pri_girl]])
                continue;
            matched[cur] = pri_girl;
            if(check[pri_girl]){
                q.push(check[pri_girl]);
                // 기존의 짝이 꺠진 경우
            }
            check[pri_girl] = cur;
            break;
        }
    }
    for(int i=1; i<=N; i++)
        cout<<matched[i]<<'\n';

}