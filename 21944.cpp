// recommend G x : 1이면 분류가 G인것중 가장 어려운, -1이면 가장 쉬운
// recommend2 x : 1이면 알고리즘 분류 상관없이 가장 어려운 조건을 만족하는게 여러개면 문제번호가 큰거로, -1은 쉬운거, 번호 작은거
// recommend 3 x L : 1이면 L보다 크거나 같은거 중 가장 쉬운거, 여러개면 문제 번호 작은거

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
struct Prob{
    int P,L,G;
    Prob(int p, int l, int g) : P(p), L(l), G(g){};
};
vector<Prob*>v;
unordered_map<int , pair<int, int > > m1;
void Add(Prob* prob){
    v.push_back(prob);
    if(m1.find(prob->G) != m1.end()){
        if(m1[prob->G].first < prob->L){
            m1[prob->G].first = prob->L;
        }
        else if(m1[prob->G].first == prob->L){
            if(m1[prob->G].second < prob->P)
                m1[prob->G].second = prob->P;
        }
    }
    m1.insert(make_pair(prob->G, make_pair(prob->L, prob->P)));
}
int N, M;
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        int p, l, g; cin>>p>>l>>g;
        Prob* prob = new Prob(p,l,g);
        Add(prob);
    }
    cin>>M;
    for(int i=0; i<M; i++){
        string s; cin>>s;
        if(s == "add"){
            int p, l, g; cin>>p>>l>>g;
            Prob* prob = new Prob(p,l,g);
            Add(prob);
        }else if(s == "recommend"){
            int 
        }
    }
}
