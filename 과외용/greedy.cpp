#include <iostream>
#include <queue>
using namespace std;

// 1. 우선순위 큐
// 우선순위가 높은거 부터 나오는 자료구조.
// <1, 3> <8, 2> <3, 5> <4, 6>

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp>pq;

// cmp -> 구조체, 클래스
// 구조체

struct cmp
{
    // 연산자 오버로딩
    bool operator()(pair<int,int>a, pair<int,int>b){
        return a.first > b.first;
    }
};


int main(){
    
    
}