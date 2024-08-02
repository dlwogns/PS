#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, Q;
vector<pair<int, int> >v;
bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.first < b.first;
}
int main() {
    cin>>N;
    for(int i=0; i<N; i++){
        int a; cin>>a; a+=i;
        v.push_back(make_pair(a, i));
    }
    cin>>Q;
    sort(v.begin(), v.end());
    for(int i=0; i<Q; i++) {
        int q; cin>>q;
        int ans = 987654321;
        int l = 0, r = v.size()-1;
        while(l + 1 < r) {
            int mid = (l+r)/2;
        }
    }

}