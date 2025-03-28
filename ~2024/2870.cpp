#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;

int N;
vector<string> v;
regex pattern("^0+([1-9][0-9]*)$|^0+$");

bool cmp(string& s1, string& s2) {
    if(s1.size() < s2.size()) return true;
    else if(s1.size() == s2.size()) {
        return s1 < s2;
    }
    else return false;
}

int main() {
    cin>>N;
    while(N--) {
        string s; cin>>s;
        string chk="";
        for(auto e : s) {
            if(e >='0' && e <= '9') {
                chk.push_back(e);
            }else {
                if(chk.empty()) continue;
                string chk_regex = regex_replace(chk, pattern, "$1");
                if(chk_regex.empty()) chk_regex = "0";
                v.push_back(chk_regex); chk = "";
            }
        }
        if(!chk.empty()) {
            string chk_regex = regex_replace(chk, pattern, "$1");
            if(chk_regex.empty()) chk_regex = "0";
             v.push_back(chk_regex);
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(auto e : v) cout<<e<<'\n';
}