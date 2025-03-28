#include <iostream>
using namespace std;
int T, N, D, p[1010], m[1010][1010], s[1010][1010];
// test case의 수, 행렬의 수, 소수, 행렬 곱셈의 최솟값, 최적의 부모를 찾기 위한 배열

int printopparents(int i, int j){ 
    // 최적의 부모를 찾기 위해서
    // 재귀 과정을 통해, s에 기록된 정보로 재귀를 수행.
    if(i == j) return i; //base condition
    int p1 = printopparents(i, s[i][j]);
    int p2 = printopparents(s[i][j]+1, j);
    return (p1*p1+p2*p2)%D; // (A^2 + B^2 )%D 
}

int main(){
    cin>>T;
    while(T--){
        cin>>N>>D;
        for(int i=0; i<=N; i++)
            cin>>p[i]; 
        for(int i=0; i<=N; i++)
            m[i][i] = 0; // 시작과 끝이 같은 경우에는 0을 넣어준다. (행렬이 하나만 있는 case)
            
        
        //행렬곱의 순서에 따라 곱셈횟수가 달라짐.
        // 이를 DP로 해결.
        for(int l=2; l<=N; l++){ // 모든 경우의 수를 dp로 계산한다.
            for(int i=1; i<=N-l+1; i++){
                int j = i+l-1;
                m[i][j] = 2000000000;
                // 초기 m의 값을 무한대로 지정해 값이 바뀔 수 있게 한다.
                for(int k=i; k<j; k++){
                    int q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                    // partition을 했을때의 앞의 optimal 값과 뒤의 optimal 값, 그리고 그 둘을 곱한값을 계산.
                    if(q<m[i][j]){
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
        cout<<m[1][N]<<'\n';
        cout<<printopparents(1,N)<<'\n';
    }
}