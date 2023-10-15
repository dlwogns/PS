#include <iostream>
using namespace std;
int main(){
    
    // int a[10] = {0,1,2,3,4,5,6,7,8,9};

    // //while
    // int index = 0;
    // while(index < 10){
    //     cout<<a[index]<<' ';
    //     index += 1;
    // }

    // //for
    // for(int i = 0; i<10; i += 1){
    //     // 변수 선언, 조건, 변수의 변화
    //     cout<<a[i]<<' ';
    // }

    int arr[3][3] = {
        {0,1,3},
        {0,2,2},
        {0,3,4}
    };
    // 0 1 3  (0,0) (0,1) (0,2)
    // 0 2 2  (1,0) (1,1) (1,2)
    // 0 3 4  (2,0) (2,1) (2,2)

    // 원소 : (i, j)
    for(int i=0; i<3; i += 1){
        for(int j=0; j<3; j += 1){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }

    
    


}

