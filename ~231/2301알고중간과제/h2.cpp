#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, N, ans;
int height(int* arr, int cur_node){
    if(cur_node*2 > N) return 0;
    return 1+max(height(arr, cur_node*2), height(arr, cur_node*2+1));
}
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int promote(int* arr, int hStop, int vacant, int h){
    int vacStop;
    if(h <= hStop){
        vacStop = vacant;
    }
    else if(arr[2*vacant] <= arr[2*vacant+1]){
        swap(&arr[vacant], &arr[vacant*2+1]);
        vacStop = promote(arr, hStop, 2*vacant+1, h-1);
    }else{
        swap(&arr[vacant], &arr[vacant*2]);
        vacStop = promote(arr, hStop, 2*vacant, h-1);
    }
    return vacStop;
}
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

void fixHeapFast(int* arr, int vacant, int h){
    if(h <= 1){
        if(h == 0) return;
        if(arr[vacant] < arr[vacant*2]){
            swap(&arr[vacant], &arr[vacant*2]);
        }
        if(vacant*2+1 <= N && (arr[vacant] < arr[vacant*2+1])){
            swap(&arr[vacant], &arr[vacant*2+1]);
        }
        return;
    }else{
        int hStop = h/2;
        int vacStop = promote(arr, hStop, vacant, h);
        int vacParent = vacStop/2;
        if(arr[vacParent] < arr[vacStop]){
            swap(&arr[vacStop], &arr[vacParent]);
            bubbleUpHeap(arr, vacant,arr[vacant],vacParent);
            return ;
        }else
            fixHeapFast(arr, vacStop, hStop);
    }
}
void constructHeap(int* arr, int cur_node){
    if(height(arr, cur_node) == 0) return;
    if(cur_node*2 <= N) constructHeap(arr, cur_node*2);
    if(cur_node*2+1 <= N) constructHeap(arr, cur_node*2+1);
    fixHeapFast(arr, cur_node, height(arr, cur_node));
}
void deletemax(int* arr){
    swap(&arr[1], &arr[N]);
    N -= 1;
    fixHeapFast(arr, 1, height(arr, 1));
}
void heapsort(int* arr){
    constructHeap(arr, 1);
    // for(int i=1; i<=N; i++)
    //     cout<<arr[i]<<' ';
    // cout<<'\n';
    int* e = new int[N+1];
    int t = N;
    for(int i=N; i>=1; i--){
        int curMax = arr[1];
        deletemax(arr);
        e[i] = curMax;
    }
    for(int i=1;i<=t; i++)
        cout<<e[i]<<' ';
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>N;
        int* arr = new int[2*N+1];
        for(int i=1; i<=2*N; i++)
            arr[i] = -1;
        for(int i=1; i<=N; i++)
            cin>>arr[i];
        heapsort(arr);
        
    }
}