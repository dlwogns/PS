#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, check[100001], len[100001], ans, idx;
void func(int n, int i, int a){
    if(n == 0){
        return;
    }
    if(len[i] == n && len[i] <= a){
        check[i] = 1;
        func(n-1, i-1, len[i]);
    }else{
        func(n,i-1,a);
    }
}
int main(){
    cin>>N;
    vector<pair<int,int>>arr(N);
    for(int i=0; i<N; i++)
        cin>>arr[i].first>>arr[i].second;
    sort(arr.begin(), arr.end());
    vector<int>v;
    v.push_back(0);
    for(int i=0; i<N; i++){
        if(v.back() < arr[i].second){
            len[i] = v.size();
            v.push_back(arr[i].second);
        }else{
            int left = 0, right = v.size()-1;
            while(left <= right){
                int mid = (left + right)/2;
                if(v[mid] < arr[i].second){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
            len[i] = (left+right)/2+1;
            v[(left+right)/2+1] = min(v[(left+right)/2+1], arr[i].second);
        }
    }
    for(int i=0; i<N; i++){
        if(len[i] > ans){
            ans = len[i];
            idx = i;
        }
    }
    func(ans, idx, len[idx]);
    cout<<N-ans<<'\n';
    for(int i=0; i<N; i++){
        if(!check[i]){
            cout<<arr[i].first<<' ';
        }
    }
}