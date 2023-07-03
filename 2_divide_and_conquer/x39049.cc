#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> permut(const vector<int>& v, const vector<int>& pos) {
    vector<int> res(n);
    for (int i = 0; i < n; ++i) res[i] = v[pos[i]];
    return res;
}

void potencia(const vector<int>& v, int k, vector<int>& res) {
    if (k == 0) {
        for (int i = 0; i < n; ++i) res[i] = i;
    } else {
        vector<int> aux(n);
        potencia(v,k/2,aux);
        res = permut(aux,aux);
        if (k%2 != 0) res = permut(res, v);
    }
}



int main() {
    int k;
    while (cin >> n) {
        vector<int> v(n),res(n);
        for (int &x: v) cin >> x;
        cin >> k;
        potencia(v,k,res);
        cout << res[0];
        for (int i = 1; i < n; ++i) cout << ' ' << res[i];
        cout << endl;
    }
}