#include <iostream>
using namespace std;
int foarr[6] = {444444,44444,4444,444,44,4};
int searr[6] = {777777,77777,7777,777,77,7};
int n, check1[6], check2[6];
void func(int N, int idx){
    if(idx == 6){
        cout<<-1;
        exit(0);
    }
    if(N == 0){
        cout<<'a'<<endl;
        for(int i=0; i<6; i++){
            for(int j=0; j<check1[i]; j++)
                cout<<foarr[i]<<' ';
            for(int j=0; j<check2[i]; j++)
                cout<<searr[i]<<' ';
        }
        exit(0);
    }
    if(N >= searr[idx]){
        check2[idx] += 1;
        func(N-searr[idx],idx);
    }
    if(N >= foarr[idx]){
        check1[idx] += 1;
        func(N-foarr[idx],idx);
    }else
        func(N, idx+1);
}
int main(){
    cin>>n;
    func(n, 0);

}