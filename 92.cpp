#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
int T;
int main(){
    cin>>T;
    while(T--){
        int N, ans=0; cin>>N; // ans는 CNT. 총 몇명이 상품을 받을 수 있는지
        vector<string>v; // 첫번째 입력에 대한 사람들 이름 순서대로 저장
        unordered_map<string, int>um; // 두번째 입력받은 사람들의 등수 저장
        for(int i=1; i<=N; i++){
            string s; cin>>s;
            v.push_back(s); // 첫번째 사람들 이름 입력
        }
        for(int i=1; i<=N; i++){
            string s; cin>>s;
            um[s] = i; // 두번째 입력에 따른 등수 저장(i가 등수)
        }
        int check = um[v[0]]; 
        // 첫 경기 등수에 따라 받을 수 있는 사람을 구하려면
        // 2등인 사람은 1등일 사람을 다음 경기에서 이겨야하고
        // 3등인 사람은 1, 2등중 한명을 이겨야하고 ~~~ N등까지 감.
        // 그러므로 check를 첫 경기에서 1등인 사람의 두번째 경기의 등수로 두는것이 첫번째 과정.
        for(int i=1; i<v.size(); i++){ // 첫번째 경기의 등수 순서대로 벡터에 저장해놓았으니 첫번째 경기의 2등부터 N등까지 탐색.
        // 1등은 절대 상품을 받을 수 없다. 이길사람이 없기 떄문에
            if(um[v[i]] < check)  
               ans += 1;
            // 2등부터 시작해서 check가 첫번째 경기 1등을 저장해놨으니까, 그걸 이겼으면 ans += 1;
            // N등을 경우라고 두었을때 check는 항상 그보다 등수가 높았던 사람의 현재 등수임을 알아야 한다.
            else{
               // 만약 2등이 1등보다 두번째 경기 등수가 낮으면, 상품은 못받는다.
               // 그러면 3등은 1등이 아닌 2등만 이겨도 상품을 받으니까 2등을 check에다 다시 저장.
               // N번째로 가도 같은 알고리즘으로 동작.
                check = um[v[i]];
            }
        }
        cout<<ans<<'\n';

    }
}