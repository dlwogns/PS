#include <iostream>
using namespace std;
string func(string::iterator &iter){
    char str = *(iter++);
    if(str != 'x'){
        return string(1, str);
    }
    string one = func(iter);
    string two = func(iter);
    string the = func(iter);
    string four = func(iter);
    return "x" + the + four + one + two;
}

int main(){
    
    int T; cin>>T;
    while(T--){
        string s; cin>>s;
        string::iterator iter = s.begin();
        cout<<func(iter)<<'\n';
    }
}
