#include <iostream>
#include <vector>
using namespace std;

vector<int> multMod(vector<int> m1, vector<int> m2, int mod) {
    vector<int> res(4);
    res[0] = (m1[0]*m2[0] + m1[1]*m2[2]) % mod; // a*a + b*c
    res[1] = (m1[0]*m2[1] + m1[1]*m2[3]) % mod; // a*b + b*d
    res[2] = (m1[2]*m2[0] + m1[3]*m2[2]) % mod; // c*a + d*c
    res[3] = (m1[2]*m2[1] + m1[3]*m2[3]) % mod; // c*b + d*d
    return res;
}

void power(int n, int m, vector<int>& aux) {
    vector<int> Q ({1, 1, 1, 0});
    while (n > 0) {
        if (n % 2 == 1) aux = multMod(aux, Q, m);
        Q = multMod(Q, Q, m);
        n /= 2;
    }
}

int fibonacci(int n, int m) {
    if (n < 2) return n;
    vector<int> aux({1, 0, 0, 1}); //vector identitat
    power(n, m, aux);
    return aux[1];
}

int main() {
    int n, m;
    while (cin >> n >> m)  cout << fibonacci(n, m) << endl;
}