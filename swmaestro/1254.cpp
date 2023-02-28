#include <iostream>
#include <string>
using namespace std;
string s;
int ans;
int func(int st, int dest){
    int re = dest - st + 1;
    while(st <=dest){
        if(s[st] == s[dest]){
            st += 1;
            dest -= 1;
            continue;
        }
        return 0;
    }
    return re;
}
int main(){
    cin>>s;
    int st = 0, dest = s.size()-1;
    int checkpel = 0;
    for(int i=0; i<s.size(); i++){
        checkpel = max(checkpel, func(i, s.size()-1));
    }
    cout<<s.size() + s.size() - checkpel;
}