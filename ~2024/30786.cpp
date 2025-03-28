#include <iostream>
#include <algorithm>
using namespace std;
int N, evencount, oddcount;
pair<int,int>arr[300001];
int main(){
    cin>>N;
    for(int i=1; i<=N; i++){
        int x, y; cin>>x>>y;
        arr[i] = make_pair(x,y);
        if((abs(arr[i].first - arr[i-1].first) + abs(arr[i].second - arr[i-1].second)) % 2 == 0) evencount += 1;
        else oddcount += 1;
    }
    if(oddcount == 0)
        cout<<"NO";
    else{
        if(evencount%2 == 0 && oddcount%2 == 0){

        }else{
            
        }
    }
}