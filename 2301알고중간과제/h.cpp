#include <iostream>
#include <math.h>

using namespace std;

// MAX Heap을 이용해서 오름차순 정렬을 하는 코드 입니다.

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int parent(int a) {
	return (a / 2);
}

int left_child(int a) {
	return 2 * a;
}

int right_child(int a) {
	return (2 * a + 1);
}

int promote(int* arr, int hStop, int vacant, int h, int max_size) { // arr = 배열, hStop = 얼마나 내려갈 것인지, vacant = 현재위치, h = 높이(점점내려감)
	int vacStop;// 내려갈 위치

	if (h <= hStop) { // 내려갈만큼 내려갔을경우 현재위치를 리턴시킴
		vacStop = vacant;
	}
	else if (arr[left_child(vacant)] < arr[right_child(vacant)] && right_child(vacant) <= max_size) { // 우측 자식이 더 클 경우
		swap(&arr[vacant], &arr[right_child(vacant)]);
		vacStop = promote(arr, hStop, right_child(vacant), h - 1, max_size);
	}
	else{ // 좌측 자식이 더 클경우
		swap(&arr[vacant], &arr[left_child(vacant)]);
		vacStop = promote(arr, hStop, left_child(vacant), h - 1, max_size);
	}	
	
	return vacStop;
}

void BubbleUpHeap(int* arr, int root, int K, int vacant) { // root = 루트 노드, K = vacant의 원래 값, vacant = 현재 위치 (해당 코드에선 루트 = 1이지만 노드로 들어갈떄 필요하므로 넣었음)
	if (vacant == root) arr[vacant] = K;
	else {
		int Parent = parent(vacant);
		if (K < arr[Parent]) { // 부모 보다 작다면 자기위치를 찾은것
			arr[vacant] = K;
		}
		else { // 부모 보다 크다면 버블업힙을 계속 실행
			swap(&arr[vacant], &arr[Parent]);
			BubbleUpHeap(arr, root, K, Parent);
		}
	}

	return;
}

void FixHeapFast(int* arr, int vacant, int K, int h, int max_size) { // K = vaccant의 원래 값, vaccant = 현재위치(루트), h = 높이
	if (h <= 1) { // h가 1이하일경우
		if (h == 0) return;	
		else {
			if (left_child(vacant) > max_size) return; // h가 1이남았지만 해당노드의 자식이 없을수도있다.

			if (K < arr[left_child(vacant)]) swap(&arr[vacant], &arr[left_child(vacant)]);

			if (arr[vacant] < arr[right_child(vacant)] && right_child(vacant) <= max_size) swap(&arr[vacant], &arr[right_child(vacant)]);
			return;
		}
	}
	else {
		int hStop = h / 2;
		int vacStop = promote(arr, hStop, vacant, h, max_size); // 새로운 위치
		int vacParent = parent(vacStop); // 새로 찾은 위치의 부모

		if (arr[vacParent] < K) {
			swap(&arr[vacStop], &arr[vacParent]);
			BubbleUpHeap(arr, vacant, K, vacParent);
		}
		else FixHeapFast(arr, vacStop, K, hStop, max_size);
	}

	return;
}
void constructHeap(int* arr, int node, int max_size) {
	int K;
	if (left_child(node) <= max_size) { // Leaf가 아닐경우
		constructHeap(arr, left_child(node), max_size);
		constructHeap(arr, right_child(node), max_size);
		K = arr[node];
		FixHeapFast(arr, node, K, h,max_size);
	}
}

void heapSort(int* arr, int node, int size) {
	constructHeap(arr, node, size);
	
	int h; // 높이 계산

	for (int last_leaf = size; last_leaf >= 2; last_leaf--) {
		swap(&arr[1], &arr[last_leaf]);
		h = log2(last_leaf - 1);
		FixHeapFast(arr, 1, arr[1], h, last_leaf - 1);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int C;
	cin >> C;
	int *arr = new int[C + 1];
	
	for (int i = 1; i <= C; ++i) {
		cin >> arr[i];
	}

	heapSort(arr, 1, C);
	for (int i = 1; i <= C; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	delete[] arr;
	return 0;
}