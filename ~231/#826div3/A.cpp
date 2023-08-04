#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int T;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        string s1, s2;
        int size1, size2;
        cin>>s1>>s2;
        if(s1.back() == 'L') size1 = 1;
        if(s1.back() == 'M') size1 = 0;
        if(s1.back() == 'S') size1 = -1;
        if(s2.back() == 'L') size2 = 1;
        if(s2.back() == 'M') size2 = 0;
        if(s2.back() == 'S') size2 = -1;
        size1 = size1 * s1.size();
        size2 = size2 * s2.size();
        if(size1 > size2) cout<<">\n";
        else if(size1 == size2) cout<<"=\n";
        else cout<<"<\n";
    }

}