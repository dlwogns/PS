#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#define ll long long
using namespace std;
int T;

int main() {
    cin>>T;
    while(T--) {
        int n, arr[200001]={0}; cin>>n;
        for(int i=0; i<n; i++) {
            int c; cin>>c;
            arr[c] += 1;
        }
        int count = 0;
        deque<int>v;
        for(int i=0; i<n; i++) {
            if(arr[i] == 1) {
                if(count % 2 == 1)
                    v.push_back(i);
                count += 1;
            }
        }
        for(int i=0; i<=n; i++) {
            if(arr[i] == 0) {
                cout<<i<<'\n';
                break;
            }
            if(!v.empty() && v.front() == i) {
                v.pop_front();
            }
            if(v.empty()) continue;
            arr[v.front()] = 0;
            v.pop_front();
        }
    }
}