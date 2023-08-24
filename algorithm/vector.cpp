#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct A{
    int a, b, c;
};
int main(){
    // // // pointer
    // // int b = 1;
    // // int* a = &b;
    // // cout<<*a; //1

    // // vector
    // //vector<int>v(Size, initializer_value);
    // vector<int>v; // 1, 2, 3, *
    
    // v.push_back(1);
    // v.begin(); v.end(); //iterator 반복자
    // vector<int>::iterator iter = v.begin();
    // for(vector<int>::iterator iter = v.begin(); iter!=v.end(); iter++){
    //     iter - v.begin();
    // }

    // v
    
    int arr[100];

    vector<int>v;
    // 1, 2, 3
    for(int i=0; i<v.size(); i++)
        v[0];
    for(auto iter = v.begin(); iter!=end(); iter++)
        *iter;
    for(int value : v){
        value;
    }//범위 기반 반복문

}