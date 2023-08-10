#include <iostream>
#include <cmath>
using namespace std;
int arr[100001], A, B, ans[100001];
void PrimeSieve(){
    for(int i=2; i<=100000; i++) arr[i] = i;
    for(int i=2; i<=100000; i++){
        if(!arr[i]) continue;
        for(int j=i*2; j<=100000; j+=i){
            arr[j] = 0;
            int count = j;
            while(true){
                if(count%i == 0){
                    ans[j] += 1;
                    count /= i;
                    continue;
                }
                break;
            }
        }
    }

}
int main(){
    cin>>A>>B;
    PrimeSieve();
    int ans_count = 0;
    for(int i=A; i<=B; i++){
        if(arr[ans[i]]){
            ans_count += 1;
        }
    }
    cout<<ans_count;
}