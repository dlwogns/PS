#include <vector>
#include <iostream>
using namespace std;
// 우선순위 큐
// 숫자가 낮을수록 우선순위가 높다.
// sorted array, unsorted array, heap

// 1 5 3 4 2 -> array
// 1 2 3 4 5 -> sorted array
// 1 2 3 4 5 -> pq

// 1 5 3 4 2 -> array(unsorted array)
// 1 2 3 4 5 -> pq

// 연산자 오버로딩
// 사칙연산, (), [], {}, ++ , --, ==, != 
// 오버로딩 -> 기능을 재정의.
class isLess{//cmp
    public:
    bool operator()(int a, int b){
        return a < b;
    }
};

class PQ{
    private:
        vector<int>v; // 1 5 4 2 3 ->  5 4 3 2 1
        
    public:
        void insert(int e){
            vector<int>::iterator iter = v.begin();
            isLess C;
            if(v.empty()){
                v.insert(iter, e);
            }else{
                while(iter != v.end() && C(e, *iter)){
                    ++iter;
                }
                v.insert(iter, e);
            }
        }
        void removeMin(){
            v.pop_back();
        }
        void print(){

        }
};