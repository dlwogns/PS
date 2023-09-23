#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0,-1,0,1 };

int main() {
    int t, m, n, k, x, y, cnt;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cnt = 0;
        cin >> m >> n >> k;
        int graph[50][50];
        int visited[50][50];
        for(int i=0; i<50; i++)
            for(int j=0; j<=50; j++){
                graph[i][j] = 0;
                visited[i][j] = 0;
            }
        for (int j = 0; j < k; j++) {
            cin >> x >> y;
            graph[y][x] = 1;
        }
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if (graph[a][b] == 1 && visited[a][b] != 1) {
                    queue<pair<int, int > > q;
                    q.push(make_pair(a, b));
                    visited[a][b] = 1;
                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int nx = cur.first + dx[d];
                            int ny = cur.second + dy[d];
                            if (nx < 0 || nx > n || ny < 0 || ny > m) {
                                continue;
                            }
                            if (visited[nx][ny] == 1) {
                                continue;
                            }
                            if (graph[nx][ny] == 1) {
                                q.push(make_pair(nx, ny));
                                visited[nx][ny] = 1;
                            }
                        }
                    }
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}