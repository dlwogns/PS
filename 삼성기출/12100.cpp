//
// Created by 이재훈 on 25. 3. 28.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans;

vector<vector<int> >board(21, vector<int>(21));

void shift_left(vector<vector<int> >& ori) {
    vector<vector<int> > v(N);
    // 전부 왼쪽으로 이동
    for (int i=0; i<ori.size(); i++) {
        for (int j=0; j<ori[i].size(); j++) {
            if (ori[i][j]) {
                v[i].push_back(ori[i][j]);
                ori[i][j] = 0;
            }
        }
    }
    // 합치기
    for (int i=0; i<v.size(); i++) {
        if (v[i].size() < 1) continue;
        int idx = 0;
        for (int j=0; j<v[i].size(); j++) {
            ans = max(ans, v[i][j]);
            if (j == v[i].size()-1) {
                ori[i][idx] = v[i][j];
                continue;
            }
            if (v[i][j] == v[i][j+1]) {
                ori[i][idx] = v[i][j] * 2;
                ans = max(ans, ori[i][idx]);
                idx += 1;
                j += 1;
            }
            else {
                ori[i][idx] = v[i][j];
                idx += 1;
            }
        }
    }
}
void shift_right(vector<vector<int> >& ori) {
    vector<vector<int> > v(N);
    // 오른쪽 원소 부터 v에 저장
    for (int i=0; i<ori.size(); i++) {
        for (int j=ori[i].size()-1; j>=0; j--) {
            if (ori[i][j]) {
                v[i].push_back(ori[i][j]);
                ori[i][j] = 0;
            }
        }
    }

    for (int i=0; i<v.size(); i++) {
        if (v[i].size() < 1) continue;
        int idx = 0;
        for (int j=0; j<v[i].size(); j++) {
            ans = max(ans, v[i][j]);
            if (j == v[i].size()-1) {
                ori[i][ori.size()-1 - idx] = v[i][j];
                continue;
            }
            if (v[i][j] == v[i][j+1]) {
                ori[i][ori.size()-1 - idx] = v[i][j] * 2;
                ans = max(ans, ori[i][ori.size()-1 - idx]);
                idx += 1;
                j += 1;
            }
            else {
                ori[i][ori.size()-1 - idx] = v[i][j];
                idx += 1;
            }
        }
    }
}
void shift_up(vector<vector<int> >& ori) {
    vector<vector<int> > v(N);
    // 위쪽 원소 부터 v에 저장
    for (int j=0; j<ori.size(); j++) {
        for (int i=0; i<ori.size(); i++) {
            if (ori[i][j]) {
                v[j].push_back(ori[i][j]);
                ori[i][j] = 0;
            }
        }
    }

    for (int i=0; i<v.size(); i++) {
        int idx = 0;
        for (int j=0; j<v[i].size(); j++) {
            ans = max(ans, v[i][j]);
            if (j == v[i].size()-1) {
                ori[idx][i] = v[i][j];
                continue;
            }
            if (v[i][j] == v[i][j+1]) {
                ori[idx][i] = v[i][j]*2;
                ans = max(ans, ori[idx][i]);
                idx += 1;
                j += 1;
            }else {
                ori[idx][i] = v[i][j];
                idx += 1;
            }
        }
    }
}
void shift_down(vector<vector<int> >& ori) {
    vector<vector<int> > v(N);
    // 위쪽 원소 부터 v에 저장
    for (int j=0; j<ori.size(); j++) {
        for (int i=ori.size()-1; i>=0; i--) {
            if (ori[i][j]) {
                v[j].push_back(ori[i][j]);
                ori[i][j] = 0;
            }
        }
    }

    for (int i=0; i<v.size(); i++) {
        int idx = 0;
        for (int j=0; j<v[i].size(); j++) {
            ans = max(ans, v[i][j]);
            if (j == v[i].size()-1) {
                ori[ori.size()- 1-idx][i] = v[i][j];
                continue;
            }
            if (v[i][j] == v[i][j+1]) {
                ori[ori.size()- 1 -idx][i] = v[i][j]*2;
                ans = max(ans, ori[ori.size()- 1 -idx][i]);
                idx += 1;
                j += 1;
            }else {
                ori[ori.size()- 1 -idx][i] = v[i][j];
                idx += 1;
            }
        }
    }
}


void func(vector<int>& idx, vector<vector<int> >& v) {
    if (idx.size() == 5) {
        auto ori = v;
        for (auto e : idx) {
            if (e == 0) shift_left(ori);
            if (e == 1) shift_right(ori);
            if (e == 2) shift_up(ori);
            if (e == 3) shift_down(ori);
        }
        return;
    }

    for (int i=0; i<4; i++) {
        idx.push_back(i);
        func(idx, v);
        idx.pop_back();
    }
}
int main(){
    // initiate
    cin>>N;
    board.resize(N, vector<int>(N, 0));
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin>>board[i][j];

    vector<int>idx;

    func(idx, board);
    cout<<ans;

}