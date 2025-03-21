#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
vector<int>v;

int main() {
    for(int i=1; i<=3; i++) {
        for(int j=pow(10, i-1); j<pow(10, i); j++) {
            for(int k=1; k<pow(10, 6-i+1); k++) {
                string t = to_string(k) + to_string(j);
                int ret = j*k;
                string t2 = to_string(ret);
                if(t.size() != t2.size()) continue;
                int chk =0;
                sort(t.begin(), t.end());
                sort(t2.begin(), t2.end());
                for(int l=0; l<t.size(); l++) {
                    if(t[l] != t2[l]) {
                        chk = 1;
                        break;
                    }
                }
                if(chk) continue;
                v.push_back(j*k);
            }
        }
    }
    sort(v.begin(), v.end());
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin>>N && N) {
        cout<<v[lower_bound(v.begin(), v.end(), N)-v.begin()]<<endl;
    }
}