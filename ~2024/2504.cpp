#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  long long ans = 0;
  cin >> s;
  vector<long long> v;
  for (auto c : s) {
    if (v.empty())
      v.push_back(-1 * c);
    else {
      if (c == ')') {
        long long chk = 0;
        while (!v.empty() && v.back() != (-1 * '(') && v.back() != (-1 * '[')) {
          chk += v.back();
          v.pop_back();
        }
        if (!v.empty() && v.back() == (-1 * '(')) {
          v.pop_back();
          if (chk == 0) {
            v.push_back(2);
          } else {
            v.push_back(chk * 2);
          }
        } else {
          cout << 0;
          return 0;
        }

      } else if (c == ']') {
        long long chk = 0;
        while (!v.empty() && v.back() != (-1 * '(') && v.back() != (-1 * '[')) {
          chk += v.back();
          v.pop_back();
        }
        if (!v.empty() && v.back() == (-1 * '[')) {
          v.pop_back();
          if (chk == 0) {
            v.push_back(3);
          } else {
            v.push_back(chk * 3);
          }
        } else {
          cout << 0;
          return 0;
        }
      } else {
        v.push_back(-1 * c);
      }
    }
  }
  for (auto i : v) {
    if (i == (-1 * '(') || i == (-1 * '[') || i == (-1 * ')') ||
        i == (-1 * ']')) {
      cout << 0;
      return 0;
    }
    ans += i;
  }
  cout << ans;
}