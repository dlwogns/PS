#include <iostream>
#include <string>
using namespace std;
string s, s1;
int ans;
string strans(string source){
    string dest;
    for(int i=0; i<source.size(); i++)
        if(source[i] == '1') ans += 1;
        else dest.push_back(source[i]);
    if(dest.empty()) return dest;
    int num = stoi(dest);
    dest = to_string(num);
    return dest;
}
int main(){
    cin>>s;
    s1 = strans(s);
    while(!s1.empty()){
        if(stoi(s1) == 0) break;
        if(s1.back() == '0'){
            int num = stoi(s1) - 1;
            ans += 1;
            s1 = to_string(num);
            s1 = strans(s1);
        }else{
            ans += s1.back() - '1' + 1;
            s1.pop_back();
        }
    }
    cout<<ans;
    
}