#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int>v;
vector<int>ans;
vector<int>idx;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++){
        int input;
        cin>>input;
        if(v.empty()){
            v.push_back(input);
            ans.push_back(0);
            idx.push_back(i);
        }else{
            while(!v.empty() && v.back() <= input){
                v.pop_back();
                idx.pop_back();
            }
            if(v.empty()){
                v.push_back(input);
                ans.push_back(0);
                idx.push_back(i);
            }else{
                ans.push_back(idx.back());
                v.push_back(input);
                idx.push_back(i);
            }
        }
    }
    for(auto n : ans)
        cout<<n<<' ';
}