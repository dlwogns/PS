#include <iostream>
using namespace std;
long long N, arr[1000001];
int main(){
    cin>>N;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    for(int i=4; i<=N; i++){
        if(i%3==1){
            arr[i] = arr[i-2]*2%10007;
        }else if(i%3==2)
            arr[i] = arr[i-2]*2%10007;
        else
            arr[i] = arr[i-3]*3%10007;
    }
    cout<<arr[N];

}