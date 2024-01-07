#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#define ld long double
using namespace std;
int N;
ld ans;
vector<ld>x;
vector<ld>y;
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        ld x1, y1; cin>>x1>>y1;
        x.push_back(x1);
        y.push_back(y1);
    }
    x.push_back(x[0]);
    y.push_back(y[0]);
    for(int i=1; i<N; i++){
        ans += (x[i] - x[0]) * (y[i+1] - y[0]) - (x[i+1] - x[0]) * (y[i] - y[0]);
    }
    cout<<fixed;
    cout.precision(1);
    cout<<abs(ans/2);
}