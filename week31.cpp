#include <iostream>
#include <algorithm>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
int T;
int main() {
	cin >> T;
	while (T--) {
		int n, x1, y1, x2, y2;
		cin >> n >> x1 >> y1 >> x2 >> y2;
		int d1=min(min(x1, n-y1+1), min(n-x1+1, y1)), d2 = min(min(x2, n - y2 + 1), min(n - x2 + 1, y2));
		cout << abs(d1 - d2) << '\n';
	}
}