#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int a, ans=0; cin>>a;
    string s; 
    for(int i=0; i<a; i++) {
        cin>>s;

        vector<char>v;

        for(int i=0; i<s.size(); i++) {
            if(v.empty()) v.push_back(s[i]);
            else {
                if(v.back() == s[i]) v.pop_back();
                else v.push_back(s[i]);
            }
        }
        if(v.empty()) ans += 1;
    }
    cout<<ans;
}