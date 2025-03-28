#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define pii pair<int,int> 
#define ll long long
using namespace std;
long long N, check[100001], ans;
vector<pii>xv;  
vector<pii>yv;
vector<pii>zv;
vector<pair<ll,pii > >edges;
int Find(int n){
    if(check[n] == n){
        return n;
    }
    return check[n] = Find(check[n]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a < b) check[b] = a;
    else check[a] = b;
}
int main(){
    fastio;
    cin>>N;
    for(int i=1; i<=N; i++){
        int x, y, z; cin>>x>>y>>z;
        xv.push_back(make_pair(x,i));
        yv.push_back(make_pair(y,i));
        zv.push_back(make_pair(z,i));
    }
    for(int i=1; i<=N; i++)
        check[i] = i;
    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());
    sort(zv.begin(), zv.end());
    for(int i=0; i<N-1; i++){
        edges.push_back(make_pair(xv[i+1].first - xv[i].first, make_pair(xv[i].second,xv[i+1].second)));
        edges.push_back(make_pair(yv[i+1].first - yv[i].first, make_pair(yv[i].second,yv[i+1].second)));
        edges.push_back(make_pair(zv[i+1].first - zv[i].first, make_pair(zv[i].second,zv[i+1].second)));
    }
    sort(edges.begin(),edges.end());
    for(int i=0; i<edges.size(); i++){
        int c1 = edges[i].second.first, c2 = edges[i].second.second;
        int p1 = Find(c1), p2 = Find(c2);
        if(p1 != p2){
            Union(c1,c2);
            ans += edges[i].first;
        }
    }
    cout<<ans;
}

