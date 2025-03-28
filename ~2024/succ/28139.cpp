#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
vector<pair<int,int > >v;
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }
    double sum = 0;
    for(int i=0; i<N; i++){
        double e;
        for(int j=i+1; j<N; j++){
            if(i == j) continue;
            e += sqrt(pow(v[i].first - v[j].first,2) + pow(v[i].second - v[j].second, 2));
        }
        sum += e;
    }
    double f = sum/3;
    cout<<(2 * sum - f*3)/3;
}