#include <iostream>
#include <regex>
#include <string>
using namespace std;
bool matchReg(const string& str) {
    regex reg("(100+1+|01)+");
    return regex_match(str, reg); 
}

int main() {
    string str;
    cin>>str;
    if(matchReg(str)) cout<<"SUBMARINE"<<endl;
    else cout<<"NOISE"<<endl;
}