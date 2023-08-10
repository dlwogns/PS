#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int check,check2, a, b;
int main(){
    cin>>s;
    int st =0, dest = s.size()-1;
    while(st <= dest){
        if(s[st] != s[dest]){
            check = 1;
            break;
        }
        if(a == 0 && b == 0){
            a = s[st];
            b = s[dest];
        }else{
            if(a != s[st] || b != s[dest])
                check2 = 1;
        }
        st += 1;
        dest -= 1;
    }

    if(check == 1)
        cout<<s.size();
    else if(check2 == 0)
        cout<<-1;
    else
        cout<<s.size()-1;
}