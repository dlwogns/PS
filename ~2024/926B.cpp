#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int t;
int main() {
    cin>>t;
    while(t--) {
        long long n, k; cin>>n>>k;
        cout<<k/2 + max((int)(k - pow(n, 2)/2), 0)<<'\n'; 
    }
}