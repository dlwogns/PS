#include <iostream>
#include <string>
using namespace std;
int N, ans;
int main(){
    cin>>N;
    while(N--){
        string s;
        cin>>s;
        string s2 = s.substr(2);
        if(stoi(s2) <= 90) ans += 1;
    }
    cout<<ans;
}