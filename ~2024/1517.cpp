#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[500001];
int darr[500001];
long long func(int left, int right){
    if(left == right)
        return 0;
    if(left + 1 == right){
        if(arr[right] < arr[left]){
            swap(arr[right], arr[left]);
            return 1;
        }
        return 0;
    }
    int mid = (left+right)/2;
    long long merge = func(left, mid) +func(mid+1, right);
    long long  lo = left, hi = mid+1, idx = left;
    while(lo <= mid || hi <= right) {
        if(lo <= mid && (hi > right || arr[lo] <= arr[hi])){
            darr[idx] = arr[lo];
            idx += 1;
            lo += 1;
            continue;
        }else{
            merge += hi - idx;
            darr[idx] = arr[hi];
            idx += 1;
            hi += 1;
        }
    }
    for(int i=left; i<=right; i++){
        arr[i] = darr[i];
    }
    return merge;
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    cout<<func(0, N-1);

}

// 1342
// 13 42
// 1 3 4 2