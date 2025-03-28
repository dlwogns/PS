#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
long long C, N, fence[100001];
long long sol(long long left, long long right){
    if(left == right){
        return fence[left];
    }
    long long mid = (left+right)/2;
    long long ans = max(sol(left, mid), sol(mid+1, right));
    long long midHeight = min(fence[mid], fence[mid+1]); 
    long long lo = mid, hi = mid+1;
    ans = max(midHeight * 2, ans);
    while(left < lo || hi < right){
        if((hi < right) && (left == lo || fence[hi+1] > fence[lo-1])){
            hi += 1;
            midHeight = min(midHeight, fence[hi]);
        }else{
            lo -= 1;
            midHeight = min(midHeight, fence[lo]);
        }
        ans = max(ans, midHeight * (hi-lo+1));
    }
    return ans;
}
int main(){
        cin>>N;
        for(long long i=0; i<N; i++)
            cin>>fence[i];
            cout<<sol(0, N-1)<<'\n';
}