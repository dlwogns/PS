// 1. 하나씩 나머지 구하면서 666 연속하는거 찾기.
// 2. pattern matching
// int -> string
// 
#include <iostream>
#include <string>
using namespace std;
int N, i = 1;
int main(){
    cin>>N;
    while(N){ 
        if(to_string(i).find("666") != string::npos){
            // pattern matching(string)
            // to_string(i) => int -> string (string STL)
            // find(string s) -> 어떤 string안에 s가 있는지.
            // find -> return pointer -> 없을때는 string::npos
            N -= 1;
            if(N == 0){
                cout<<i;
                return 0;
            }
        }
        i += 1;
    }
}
// bruteforce
// 완전탐색
// N < O(N) < N^2
