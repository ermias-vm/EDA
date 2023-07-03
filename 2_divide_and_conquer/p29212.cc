#include <iostream>
using namespace std;

int expo_modular(int n, int k, int m) {
    int result = 1;
    n = n % m;
    while (k > 0) {
        if (k % 2 == 1) result = (result * n) % m;
        k = k / 2;
        n = (n * n) % m;
    }
    return result;
}

int main() {
    int n, k, m;
    while (cin >> n >> k >> m) {
        int result = expo_modular(n, k, m);
        cout << result << endl;
    }
}