#include <iostream>
#include <string>
#include <vector>
using namespace std;
int T;
int main(){
    cin>>T;
    while(T--){
        long long opernum, arr1[26]={0}, arr2[26]={0}, s1 = 1;
        cin>>opernum;
        arr1[0] = 1;
        arr2[0] = 1;
        for(int i=0; i<opernum; i++){
            int d, k, check=0;
            string s;
            cin>>d>>k;
            cin>>s;
            for(int j=0; j<s.size(); j++){
                if(d == 1){
                    arr1[s[j]-'a'] += k;
                    s1 += k;
                }else if(d==2)
                    arr2[s[j]-'a'] += k;
            }
            for(int j=1; j<26; j++){
                if(arr2[j]) check = 1;
            }
            if(check == 0 && s1 - arr1[0] == 0 && arr2[0] > arr1[0]) check = 1;

            if(check) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}