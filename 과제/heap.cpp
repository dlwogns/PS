#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int T, N;
void heapSort(){
    // for(int i=n; i>=1; i--)
    //     cur_max = getMax(H);
    //     deleteMax(H);
    //     E[i] = curMax;

}
int hei(vector<int>& v, int cur){
    if(2 * cur > N)
        return 0;
    if(2*cur +1 > N)
        return 1+hei(v, cur*2);
    else
        return 1+max(hei(v, cur*2), hei(v, cur*2+1));
}

void Swap(vector<int>&v,int a, int b){
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}
int P(vector<int>&v ,int hStop, int vacant, int h){
    int vacStop = vacant;
    if(h <= hStop)
        vacStop = vacant;
    else if(v[2*vacant] <= v[2*vacant+1]){
        Swap(v, vacant, vacant*2+1);
        //v[vacant] = v[vacant*2+1];
        //vacStop = P(v ,K ,(hStop-1)/2, 2*vacant+1, hei(v,2*vacant+1));
        vacStop = P(v ,hStop, 2*vacant+1, h-1);
    }else if(v[2*vacant] > v[2*vacant+1]){
        Swap(v, vacant, vacant*2);
        //v[vacant] = v[vacant*2];
        //vacStop = P(v, K, (hStop-1)/2, 2*vacant, hei(v, 2*vacant));
        vacStop = P(v ,hStop, 2*vacant, h-1);
    }
    return vacStop;
}
void bubbleUpHeap(vector<int>&v, int K, int vacant){
    if(vacant == 1){
        //v[vacant] = K;
        return;
    }else{
        int parent = vacant/2;
        if(K <= v[parent])
            //v[vacant] = K;
            return;
        else{
            //v[vacant] = v[parent];
            Swap(v, vacant, parent);
            bubbleUpHeap(v, K, parent);
        }
    }
}
void fixHeapFast(vector<int>&v, int K, int vacant, int h){
    if(h<=1){
        if(h == 0) return;
        if(vacant*2 > N) return;
        if(K < v[vacant*2]) Swap(v,vacant, vacant*2);
        if(vacant*2+1 <= N && K < v[vacant*2 + 1]) Swap(v,vacant, vacant*2+1);
    }else{
        int hStop = h/2;
        int vacStop = P(v, hStop, vacant, h);
        int vacParent = vacStop/2;
        if(v[vacParent] <= K){
            //v[vacStop] = v[vacParent];
            Swap(v, vacStop, vacParent);
            bubbleUpHeap(v, K, vacant);
        }else{
            fixHeapFast(v, K, vacStop, hStop);
        }
    }
}
void constructHeap(vector<int>& v, int cur, int h){
    if(cur*2 <= N)
        constructHeap(v, cur*2, hei(v, cur*2));
    if(cur*2+1 <= N)
        constructHeap(v, cur*2 + 1, hei(v, cur*2+1));
    fixHeapFast(v, v[cur], cur, hei(v, cur));
}
// int deleteMax(vector<int>& v){
//     // copy the rightmost element of the lowest level of H into K
//     // delete the rightmost element on the lowest level of H
//     // fixHeap(H, K);
// }

int main(){
    cin>>T;
    while(T--){
        cin>>N;
        vector<int>v(100001, 0);
        for(int i=1; i<=N; i++){
            cin>>v[i];
        }
        constructHeap(v, 1, log2(N));
        for(int i=1; i<=N; i++)
            cout<<v[i]<<' ';
        // cout<<endl;
        // for(int i=1; i<=N; i++)
        //     cout<<deleteMax(v)<<' ';
    }
}