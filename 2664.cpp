#include <iostream>
using namespace std;
int main(){
    // 배열 선언
    int arr[9][9] = {0};
    // 입력
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>arr[i][j];
        }
    }
    // 최댓값 찾기
    int max_num = -1;
    int row = 0, col = 0;
    //row -> 행, col -> 열
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(arr[i][j]>max_num){
                max_num = arr[i][j];
                row = i;
                col = j;
            }
        }
    }
    cout<<max_num<<'\n';
    cout<<row+1<<' '<<col+1;


}