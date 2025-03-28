// priority queue
//  {2, b} {3, c} {1, a}

// sorted sequece, unsorted sequence, heap
// array -> 처음에 정렬을 해주는지, 안해주는지.

#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
// class, struct
// operator overloading

class cmp{
    bool operator() (int a, int b){
        // return true; -> 위치를 바꾼다.
        return a > b;
    }
};

priority_queue<int, vector<int>, cmp>pq; 
// 작은거부터, 큰거부터 
// -1, 1, 3

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp2>pq2;

// 최단거리 길찾기.
// 