#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[200001];
int main(){
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>arr[i];
    sort(arr, arr+N);
    (N%2==0) ? cout<<arr[N/2-1] : cout<<arr[N/2];
}