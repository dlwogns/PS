#include <iostream>
#include <string>
#include <vector>
using namespace std;
string T, P;
vector<int>ans, pi;
void compute_pi(){
    pi.assign(P.size(), 0);
    int j = 0;
    for(int i=1; i<P.size(); i++){
        while(j > 0 && P[i] != P[j]){
            j = pi[j - 1];
        }
        if(P[i] == P[j]){
            pi[i] = ++j;
        }
    }
}
void kmp(){
    int j = 0; // 현재 일치하는 문자의 수
    for(int i=0; i<T.size(); i++){
        while(j > 0 && T[i] != P[j]){
            j = pi[j-1];
        }
        if(T[i] == P[j]){
            if(j == P.size()-1){
                ans.push_back(i-P.size()+1);
                j = pi[j];
            }else{
                j += 1;
            }
        }
       
    }
}
int main(){
    getline(cin, T);
    getline(cin, P);
    compute_pi(); kmp();
    cout<<ans.size()<<'\n';
    for(auto e : ans){
        cout<<e+1<<'\n';
    }
}