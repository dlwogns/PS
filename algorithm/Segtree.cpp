#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Segment tree
// full binary tree -> 배열로 저장
// 원소가 바뀌는 구간합도 O(lgN)으로 풀이 가능.
void init(vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    if(start == end){
        // leaf node, segtree의 leaf node는 배열의 그 수 그대로 저장.
        tree[node] = a[start];
    } else{
        init(a, tree, node*2, start, (start+end)/2);
        // 왼쪽 자식은 [start, (start+end)/2]의 합이기 때문에.
        init(a, tree, node*2+1, (start+end)/2+1, end);
        // 오른쪽 자식.
        tree[node] = tree[node*2] + tree[node*2+1];
        // 현재 노드는 왼쪽자식, 오른쪽 자식의 합.
    }
}
long long query(vector<long long>&tree, int node, int start, int end, int left, int right){
    if(left > end || right < start)
        return 0;
    if(left <= start && end <= right)
        return tree[node];
    long long lsum = query(tree, node*2, start, (start+end)/2, left, right);
    long long rsum = (query(tree, node*2+1, (start+end)/2+1, end, left, right));
    return lsum + rsum;
}
void update(vector<long long>&tree, int node, int start, int end, int index, long long diff){
    if(index < start || index > end) return;
    tree[node] = tree[node]+diff;
    if(start != end){
        update(tree, node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}