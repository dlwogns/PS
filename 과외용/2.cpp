#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Array{
    private:
        int* array;
        
    public:
        Array(int N){
            array = new int[N];
        };
};

int main(){
   
    // 자료구조
    // Array
    // 배열
    // 수를 입력받고, 그 수가 배열의 사이즈가 됨.
    // 멤버 함수 -> size, find
    // size -> 현재 몇개의 원소가 들어가 있는지.
    // insert -> 배열에 값을 넣어준다. 사이즈가 넘치면 -1 출력.
    // delete -> 배열의 값을 삭제한다. 배열이 비어있으면 -1 출력.
    // find -> 어떤 수를 입력받고, 그 수가 배열에 존재 하는지. 존재한다면 해당하는 인덱스 출력. 존재하지 않는다면 -1 출력

    int N;
    cin>>N;
    Array arr(N);
}
