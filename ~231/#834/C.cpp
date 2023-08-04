#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int T;
int main(){
    cin>>T;
    while(T--){
       int n, k, arr[26];
       string s;
       cin>>n>>k;
       cin>>s;
        for(auto c : s)
            arr[c-'a']+=1;
        for(int i=0; i<26; i++){
            if(arr[i] == 0) continue;
            pq.push({arr[i], arr[i]+'a'});
        }
        
    }

}