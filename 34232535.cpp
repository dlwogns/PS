#include <iostream>
#include <deque>
using namespace std;
int t;
int main(){
    cin>>t;
    while(t--){
        int n; cin>>n;
        int check = 0;
        deque<int>d;
        for(int i=1; 2*i-1 <= n; i++){
            if(!check){
                d.push_back(2*i-1);
                check = 1;
            }else{
                d.push_front(2*i-1);
                check = 0;
            }
        }
        int c = 0;
        for(int i=0; i<d.size(); i++){
            if(c == 0){
                if(d[i]+1 <= n)
                    cout<<d[i]<<' '<<d[i]+1<<' ';
                else
                    cout<<d[i]<<' ';
            }else{
                if(d[i]+1 <= n)
                    cout<<d[i]+1<<' '<<d[i]<<' ';
                else
                    cout<<d[i]<<' ';
            }
            if(d[i] == 1) c = 1;
            
        }
        cout<<'\n';
    }
}