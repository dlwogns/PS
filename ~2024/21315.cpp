//21:55
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N, ans[1001];
vector<int>arr;

vector<int>* card(int cnt, vector<int>* v) {
    if(cnt < 0) return v;
    vector<int>*tmp = new vector<int>();
    for(int i=v->size()-pow(2, cnt); i<v->size(); i++){
        tmp->push_back(*(v->begin()+i));
    }
    vector<int>*res = card(cnt-1, tmp);
    for(int i=0; i<v->size()-pow(2,cnt); i++)
        res->push_back(*(v->begin()+i));
    return res;
}

bool card(int fir, int sec) {
    vector<int>*v = new vector<int>(arr);
    vector<int>* tmp = card(fir, v);
    vector<int>* res = card(sec, tmp);
    for(int i=0; i<N; i++){
        if(*(res->begin()+i) != ans[i])
            return false;
    }
    return true;
    
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>ans[i];
        arr.push_back(i+1);
    }
    card(1,1);
    for(int i=1; pow(2, i) < N; i++)
        for(int j=1; pow(2, j) < N; j++) {
            if(card(i, j)){
                cout<<i<<' '<<j;
                return 0;
            }
        }
}