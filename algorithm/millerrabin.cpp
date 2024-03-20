#include <iostream>
#include <cmath>
#define START_VAL 3
#define LAST_VAL 1000000
using namespace std;
int a_param[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
// 밀러 라빈.
// N이 2 초과의 소수인 경우만 적용 가능.
long long power(long long x, long long y, long long mod) {
    long long res = 1;
    x %= mod;
    while(y) {
        if(y % 2) res = (res * x) % mod; // 지수가 홀수일때 짝수를 맞춰서 빠른 거듭제곱을 할 수 있도록 함.
        y /= 2;
        x = (x*x) % mod;
    }
    return res;
}
bool miller(long long n, long long a) {
    if(a % n == 0) return false;
    long long k = n-1;
    while(1) {
        long long temp = power(a, k, n);
        if(temp == n-1) return true; // -1이 나오는 경우
        if(k%2) return (temp == 1 || temp == -1); // a^d일때, n으로 나눴을때 1이나 -1이 나와야 소수.
        k /= 2; // 반복
    }
}
int main() {
    for(int n=START_VAL; n<=LAST_VAL; n++) {
        int isPrime = true;
        for(int i=0; i<11; i++) {
            if(a_param[i] == n) break;
            if(miller(n, a_param[i]) == false) {
                isPrime = false;
            }
        }
        if(isPrime) cout<<n<<' ';
    }
    
}