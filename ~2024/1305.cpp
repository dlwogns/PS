#include <iostream>
#include <vector>
#include <string>
using namespace std;

int L;
string s;
int main(){
    cin>>L>>s;
    vector<int>v(L+1,0);
    int j=0;
    for(int i=1; i<L; i++){
        while(j > 0 && s[j] != s[i]){
            j = v[j-1];
        }
        if(s[j] == s[i]){
            v[i] = ++j;
        }
    }
    cout<<L - v[L-1];
}