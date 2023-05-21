#include <iostream>
using namespace std;
int func1(int b){
    return b;
}
int func2(int* arr){
    return arr[5];
}
int main(){
    // call by value, call by reference
    int a = 5;
    int* b = &a;
    // * -> 포인터, 역참조
    // & -> 레퍼런스, 참조
    // &, * -> 연산자. 자료형* -> ~~ 타입 포인터 변수
    // 포인터 변수는 주소값을 저장.
    cout<<*b;
    //cout<<func1(a);

    // 포인터 변수 -> 자료형*
    // 일단은 void빼고 다 된다.
}