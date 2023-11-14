#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
int T;
void fillstring(string& ans, string& s, char c){
    int sizet;
    (ans.empty()) ? sizet = 0 : sizet = ans.size();
    for(sizet; sizet<s.size(); sizet++)
        ans.push_back(c);
}
string func(string& s, int* arr, int maxint){
    string ans;
    for(int i=0; i<s.size(); i++){
        int findidx = 0;
        for(int j = s[i]-'0'; j>=0; j--){
            if(arr[j] && (j != 0 || i != 0)){
                ans.push_back(j+'0');
                findidx = 1;
                if(j < s[i]-'0'){
                    fillstring(ans, s, maxint+'0');
                    return ans;
                }
                break;
            }
            
        }
        if(findidx == 0){
            while(!ans.empty()){
                int check = ans.back()-'0'; ans.pop_back();
                for(int j= check-1; j>=0; j--){
                    if(arr[j]){
                        ans.push_back(j+'0');
                        fillstring(ans, s, maxint+'0');
                        check = 0; break;
                    }
                }
                if(!check) break;
            }
            if(ans.empty())
                fillstring(ans, s, maxint+'0');
            break;
        }
    }
    return ans;
}
int main(){
    fastio;
    cin>>T;
    while(T--){
        ll N, C, maxint=0; cin>>N>>C;
        int arr[10] = {0};
        for(int i=0; i<C; i++){
            ll a; cin>>a; arr[a] = 1;
            maxint = max(maxint, a);
        }
        string s = to_string(N), ans;
        cout<<stoll(func(s, arr, maxint));
    }
}
