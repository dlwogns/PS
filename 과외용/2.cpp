#include <iostream>
using namespace std;
class Node{
    public:
        Node* next;
};

// pointer
// call by value, call by reference
int func(int a, int b){
    //call by value
}
int func2(int& a, int& b){
    //call by reference
}
// value, reference

int main(){
    int a = 1;
    int* pa = &a;
    
    // & -> reference, * -> pointer
    // & -> 어떤 변수의 주소를 의미. (참조) 연산자
    cout<<&a<<endl;
    // * -> 역참조, 주소에 해당하는 값 연산자
    cout<<*pa<<endl;
    // 자료형* -> 포인터 변수 자료형(주소값을 저장)
    int* pa2 = &a;


}