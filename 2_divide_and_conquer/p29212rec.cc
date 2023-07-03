#include <iostream>
using namespace std;

int expo_modular(int n, int k, int m) {
    if (k == 0) return 1;
    else {
        int y = expo_modular(n,k/2,m);
        if (k%2 == 0) return (y*y)%m;
        return (((y*y)%m)*n)%m;
    }
}

int main() {
    int n, k, m;
    while (cin >> n >> k >> m) {
        int result = expo_modular(n%m, k, m);
        cout << result << endl;
    }
}