#include <iostream>
#include <string>
#include <vector>
using namespace std;
class cal;
int main(){
    // // 동적 할당
    // // 정적(static) 동적(dynamic)
    // int a[10];

    // //동적할당의 예시
    // int N;
    // cin>>N;
    // int* b = new int[N];
    // // , vector

    // // new 할당
    // // new type; 
    // // 배열이면 new type[값];
    // int* v1 = new int;
    
    // // delete 해제
    // // delete
    // delete v1;


    // vector
    //vector<int>v;
    // v.push_back 할때마다 v의 길이가 하나씩 늘어난다.
    
    int N = 100;
    vector<int>v(N, 7); // (사이즈, 전체 사이즈를 초기화할 값)
    // string -> vector<char>v
    string s;
    cin>>s;

    // 전역변수 지역변수 (scope)
    // 상수와 변수
    // static

}