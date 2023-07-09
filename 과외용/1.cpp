#include <iostream>
#include <string>
using namespace std;

class Array{
    private:
        int* arr;
    public:
        Array(int N){
            arr = new int[N];
        }
        void Insert(int data, int index){
            // 인덱스에 값을 넣어준다.
        }
        void Erase(int index){
            // 인덱스에 해당하는 값을 빼준다. (0 으로 바꿔준다)
        }
        int find(int data){
            // 배열 안에 data가 있으면 1 return, 없으면 0 return
        }
        int Size(){
            //return size;
        }
};

int main(){
    // Array
    // 배열 -> 자료의 나열
    // index based
    // insert -> insert variables based on index
    // erase 
    // size
    // find
    // 정수를 입력받고, 그 정수를 사이즈로 하는 배열을 구현하라.
    int N; // size
    cin>>N;
    string s;// 명령어
    cin>>s;
    
}