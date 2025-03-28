#include <iostream>
#include <string>
using namespace std;
int N;
string s[51], ans;
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>s[i];
    }
    for(int i=0; i<N; i++){
        char c = s[0][i];
        for(int j=1; j<s[i].size(); j++){
            if(s[i][j] != c){
                c = '?';
                break;
            }
        }
        cout<<c;
        ans.push_back(c);
    }
    cout<<ans;
}