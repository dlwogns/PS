#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string>s;
int main(){
    for(int i=0; i<4; i++){
        string st; cin>>st;
        s.insert(st);
    }
    for(auto iter = s.begin(); iter!=s.end(); iter++)
        for(auto iter2 = s.begin(); iter2!=s.end(); iter2++){
            cout<<*iter<<' '<<*iter2<<'\n';
        }

}