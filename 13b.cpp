#include <iostream>
#include <string>
#include <vector>
using namespace std;
int T;
int main(){
    cin>>T;
    while(T--){
        string s; cin>>s;
        // pi(prefix == suffix) 배열을 s의 사이즈 만큼 할당해준다.
        vector<int>prefix_table(s.size(), 0);
        int j=0; 
        // pi 배열 체크 
        for(int i=1; i<s.size(); i++){
            while(j>0 && s[i] != s[j]){
                j = prefix_table[j-1];
            }
            if(s[i] == s[j]){
                prefix_table[i] = ++j;
            }
        }
        // 문자열의 마지막이 접두사와 중복된 채로 끝난다면 해당 중복 문자열의 길이만큼 광고 문자열을 감소시킬 수 있다.
        // 전체 길이 - 마지막 접두사의 길이 
        for(int i=0; i<s.size() - prefix_table[s.size()-1]; i++){
            cout<<s[i];
        }
        cout<<'\n';
    }
}
// abcabcab
// 0 0 0 1 2 3 4 5
// -> 3, abc