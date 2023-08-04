#include <iostream>
#include <string>
using namespace std;
int T;
string s;
int main(){
    cin>>T;
    while(T--){
        cin>>s;
        int ans =1;
        if(s.size() == 1 && (s[0] != 'Y' && s[0] != 'e' && s[0] != 's')) ans = 0;
        for(int i=0; i<s.size()-1; i++){
            if(s[i] != 'Y' && s[i] != 'e' && s[i] != 's'){
                ans = 0;
                break;
            }
            if((s[i] == 'Y' && s[i+1] == 'e') || (s[i] == 'e' && s[i+1] == 's') || (s[i] == 's' && s[i+1] == 'Y')) continue;
            else{
                ans = 0;
                break;
            }
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}