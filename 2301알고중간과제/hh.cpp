#include <iostream>
#include <math.h>
using namespace std;
int T, ans=0;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int height(int* arr, int cur, int N){
    int h=0;
    for(int i = cur*2; i<=N ; i = i * 2)
        h += 1;
    return h;
}

void bubbleUpHeap(int* arr, int root, int K, int vacant){ // K -> root 값
    if(vacant == root)
        arr[vacant] = K;
    else{
        int parent = vacant / 2;
        if(K <= arr[parent]){
            arr[vacant] = K;
        }else{
            swap(&arr[vacant], &arr[parent]);
            ans += 1;
            bubbleUpHeap(arr, root, K, parent);
        }
    }
}
int promote(int* arr, int hStop, int vacant, int h){
    int vacStop;
    if(h <= hStop)
        vacStop = vacant;
    else if(arr[2*vacant] < arr[2*vacant + 1]){
        swap(&arr[vacant], &arr[2*vacant+1]);
        ans += 1;
        vacStop = promote(arr, hStop, 2*vacant+1, h-1);
    }else{
        swap(&arr[vacant], &arr[2*vacant]);
        ans += 1;
        vacStop = promote(arr, hStop, 2*vacant, h-1);
    }
    return vacStop;
}
void fixHeapFast(int* arr, int N, int K, int vacant, int h){
    if(h <= 1){
        if(h == 0)  return;
    
        int vacCheck;
        if(arr[vacant*2] >= arr[vacant*2+1])
            vacCheck = vacant*2;
        else
            vacCheck = vacant*2+1;
        if(arr[vacant] < arr[vacCheck]){
            swap(&arr[vacant], &arr[vacCheck]);
            ans += 1;
        }
        return;
    }else{
        int hStop = h/2;
        int vacStop = promote(arr, hStop, vacant, h);

        int vacParent = vacStop/2;
        if(arr[vacParent] <= K){
            swap(&arr[vacStop], &arr[vacParent]);
            ans += 1;
            bubbleUpHeap(arr, vacant, K, vacParent);
        }else{
            fixHeapFast(arr, N, K, vacStop, hStop);
        }
    }
}

void constructHeap(int* arr, int root, int N){
    if(root*2 > N) return;
    if(root * 2 <= N)
        constructHeap(arr, root*2, N);
    if(root * 2 + 1 <= N)
        constructHeap(arr, root*2+1, N);
    fixHeapFast(arr, N, arr[root], root, height(arr, root, N));
}

void deleteMax(int* arr, int N){
    arr[1] = arr[N];
    arr[N] = -1;
    ans += 1;
    fixHeapFast(arr, N-1, arr[1], 1, height(arr, 1, N-1));
}

void heapSort(int* arr, int N){
    constructHeap(arr, 1, N);
    ans = 0;
    for(int i=1; i<=N; i++)
        cout<<arr[i]<<' ';
    cout<<'\n';
    int* e = new int[N+1];
    int t = N;
    for(int i=N; i>1; i--){
        int curMax = arr[1];
        deleteMax(arr, t);
        t -= 1;
        e[i] = curMax;
    }
    cout<<ans<<'\n';
}


int main(){
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int* arr = new int[2*N+1];
        for(int i=1; i<=2*N; i++)
            arr[i] = -1;
        for(int i=1; i<=N; i++)
            cin>>arr[i];
        heapSort(arr, N);
        ans = 0;
    }
}