#include <iostream>
#include <string>
using namespace std;
int num1, num2;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
bool solve(int l, int r) {
    if(l == num1 && r == num2) return true;
    if(l+r > num1+num2) return false;
    int gcd1 = gcd(r, l+r);
    int gcd2 = gcd(r+l, l);
    if(solve(r/gcd1, (l+r)/gcd1)) {
        cout<<'L';
        return true;
    }
    else if(solve((r+l)/gcd2, l/gcd2)) {
        cout<<'R';
        return true;
    }
    return false;
}
int main() {
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin>>s;
    int idx = s.find('/');
    num1 = stoi(s.substr(0, idx));
    num2 = stoi(s.substr(idx+1));
    solve(1, 1);
}

// r/l+r, r+l/l