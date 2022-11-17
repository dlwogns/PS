#include <iostream>
using namespace std;
int main() {
    int a = 1;
    double b = 1.1;
    double c = 3;
    if (a == b && b == c && c != a) {
        cout << "true" << '\n';
    } else {
        cout << "false" << '\n';
    }
    return 0;
}