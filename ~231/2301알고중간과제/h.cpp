#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, N;
int height(int* arr, int cur_node){
    if(cur_node*2 > N) return 0;
    return 1+max(height(arr, cur_node*2), height(arr, cur_node*2+1));
}
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// int promote(int* arr, int hStop, int vacant, int h){
//     if(h <= hStop) return vacant;
//     if(vacant*2+1<=N && (arr[vacant*2+1] >= arr[vacant*2])){
//         swap(&arr[vacant], &arr[vacant*2+1]);
//         return promote(arr, hStop, vacant*2+1, h-1);
//     }
//     else{
//         swap(&arr[vacant], &arr[vacant*2]);
//         return promote(arr, hStop, vacant*2, h-1);
//     }
// }
int promote(int* arr, int hStop, int vacant, int h){
    int vacStop;
    if(h <= hStop)
        vacStop = vacant;
    else if(arr[2*vacant] <= arr[2*vacant+1]){
        swap(&arr[vacant], &arr[vacant*2+1]);
        vacStop = promote(arr, hStop, 2*vacant+1, h-1);
    }else{
        swap(&arr[vacant], &arr[vacant*2]);
        vacStop = promote(arr, hStop, 2*vacant, h-1);
    }
    return vacStop;
}
// void BubbleupHeap(int* arr, int root, int vacant){
//     if(vacant == root){
//         arr[vacant] = arr[root];
//         return;
//     }
//     if(arr[vacant] < arr[vacant/2])
//         arr[vacant] = arr[root];
//     else{
//         swap(&arr[vacant], &arr[vacant/2]);
//         BubbleupHeap(arr, root, vacant/2);
//     }
    
// }
void bubbleUpHeap(int* arr, int root, int K, int vacant){
    if(vacant == root)
        arr[vacant] = K;
    else{
        int parent = vacant/2;
        if(K <= arr[parent])
            arr[vacant] = K;
        else{
            arr[vacant] = arr[parent];
            bubbleUpHeap(arr, root, K, parent);
        }
    }
}

int fixHeapFast(int* arr, int vacant, int h){
    if(h <= 1){
        if(h == 0) return 0;
        int flag = 0;
        if(arr[vacant] < arr[vacant*2]){
            swap(&arr[vacant], &arr[vacant*2]);
            flag = 1;
        }
        if(vacant*2+1 <= N && (arr[vacant] < arr[vacant*2+1])){
            swap(&arr[vacant], &arr[vacant*2+1]);
            flag = 1;
        }
        if(flag) return 1;
        return 0;
    }else{
        int hStop = h/2;
        int vacStop = promote(arr, hStop, vacant, h);
        int vacParent = vacStop/2;
        if(arr[vacParent] < arr[vacStop]){
            swap(&arr[vacStop], &arr[vacParent]);
            bubbleUpHeap(arr, vacant,arr[vacant],vacParent);
            return 1;
        }else
            return 1 + fixHeapFast(arr, vacStop, hStop);
    }
}
void constructHeap(int* arr, int cur_node){
    if(height(arr, cur_node) == 0) return;
    if(cur_node*2 <= N) constructHeap(arr, cur_node*2);
    if(cur_node*2+1 <= N) constructHeap(arr, cur_node*2+1);
    fixHeapFast(arr, cur_node, height(arr, cur_node));
}
int heapsort(int* arr){
    if(N == 1) return 0;
    swap(&arr[1], &arr[N]);
    N-=1;
    int a = fixHeapFast(arr, 1, height(arr, 1));
    return 1 + a + heapsort(arr);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>N;
        int* arr = new int[2*N+1];
        for(int i=1; i<=N; i++)
            cin>>arr[i];
        constructHeap(arr, 1);
        for(int i=1; i<=N; i++)
            cout<<arr[i]<<' ';
        cout<<endl;
        cout<<heapsort(arr);
        cout<<endl;
    }
}