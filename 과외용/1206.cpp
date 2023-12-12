#include <iostream>
#include <vector>
using namespace std;
int T;
int func(int st, int dest, int* arr){
    if(arr[dest]^arr[st-1] != 3){
        return 1;
    }
    
}
int main(){
    cin>>T;
    while(T--){
        int N, ans = 0; cin>>N;
        int* arr = new int[N+1];
        vector<int>v;
        arr[0] = 0;
        for(int i=1; i<=N; i++){
            cin>>arr[i]; 
            if(arr[i] == 3)
                v.push_back(i);
            arr[i] = arr[i]^arr[i-1];   
        }
        int st = 1, dest = N;

        
    }
}