#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
int T;
int main() {
	fastio;
	cin>>T;
	while(T--){
		ll N, C, maxint=0; cin>>N>>C;
		int arr[10]={0};
		for(int i=0; i<C; i++){
			ll a; cin>>a; arr[a] = 1;
			maxint = max(maxint, a);
		}
		string s = to_string(N), ans;
		for(int i=0; i<s.size(); i++){
			int flag = 0;
			for(int j=s[i]-'0'; j>=0; j--){
				if(arr[j] && (j != 0 || i != 0)){
					ans.push_back(j+'0');
					flag = 1; 
					if(j < s[i]-'0'){
						for(int k=ans.size(); k<s.size(); k++)
							ans.push_back(maxint+'0');
						flag = 2;
					}
					break;
				}
			}
			if(flag == 2) break;
			if(flag == 0){
				while(!ans.empty()){
					int check = ans.back()-'0';ans.pop_back();
					for(int j=check-1; j>=0; j--){
						if(arr[j]){
							ans.push_back(j+'0');
							for(int k=ans.size(); k<s.size(); k++){
								ans.push_back(maxint+'0');
							}
							check = 0;
							break;
						}
					}
					if(!check) break;
				}
				if(ans.empty()){
					for(int j=0; j<s.size()-1; j++)
						ans.push_back(maxint+'0');
				}
				break;
			}
		}
		cout<<stoll(ans)<<'\n';
	}
}