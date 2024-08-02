#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, arr[200001], ans;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
int getGcd(int l, int r) {
    int g = arr[l];
    for(int i=l+1; i<=r; i++) {
        g = gcd(g, arr[i]);
    }
    return g;
}
int solve(int l, int r, int n) {
    if(n == 1) return max(arr[l], arr[r]);
    int arrsize = n/2;
    int right = getGcd(l, l+arrsize-1) + solve(l+arrsize, r, n-arrsize);

    int left = getGcd(l+arrsize, r) + solve(l,l+arrsize-1, arrsize);
    return max(left, right);
}
int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }
    cout<<solve(0, N-1, N);
}