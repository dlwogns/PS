#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int main(){
    cin>>N;
    vector<int>v;
    vector<int>ans;
    vector<int>check;
    for(int i=0; i<N; i++){
        int input;
        cin>>input;
        v.push_back(input);
    }
    while(!v.empty()){
        if(check.empty()){
            ans.push_back(-1);
            check.push_back(v.back());
            v.pop_back();
        }else if(check.back() > v.back()){
            ans.push_back(check.back());
            check.push_back(v.back());
            v.pop_back();
        }else{
            while(!check.empty() && check.back() <= v.back())
                check.pop_back();
            if(check.empty()){
                ans.push_back(-1);
                check.push_back(v.back());
                v.pop_back();
            }else{
                ans.push_back(check.back());
                check.push_back(v.back());
                v.pop_back();
            }
        }

    }
    while(!ans.empty()){
        cout<<ans.back()<<' ';
        ans.pop_back();
    }
}