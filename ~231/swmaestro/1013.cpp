#include <iostream>
#include <string>
using namespace std;
//(100+1+ | 01)+
int T;
string s;
int main(){
    cin>>T;
    while(T--){
        cin>>s;
        int check = -1;
        for(auto c : s){
            if(check == -1)
                check = c-'0';
            else{
                if(check == 1){
                    
                }
            }
        }
    }
}