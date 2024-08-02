#include <iostream>
#include <string>
using namespace std;
int g, s, ans[58], check[58], ans_num;
string W, S;
int main() {
    cin>>g>>s>>W>>S;
    for(int i=0; i<W.size(); i++) {
        ans[W[i]-'A'] += 1;
    }
    int l = 0, r = W.size()-1;
    for(int i=l; i<=r; i++)
        check[S[i]-'A'] += 1;
    while(r<S.size()) {
        int check_ans = 1;
        for(int i=0; i<58; i++) {
            if(ans[i] != check[i]) check_ans = 0;
        }
        if(check_ans) ans_num += 1;
        check[S[l]-'A'] -= 1;
        l += 1; r += 1;
        if(r == S.size()) break;
        check[S[r]-'A'] += 1;
    }
    cout<<ans_num;
}