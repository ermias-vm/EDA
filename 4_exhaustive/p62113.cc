#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using VI = vector<int>;

void escribir(VI& result, int tope, int x) {
    cout << x << " = ";
    bool primer = true;
    for (int i = 0; i < tope; i++) {
        if (result[i] != 0) {
            if (primer) {
                primer = false;
                if (i%2 != 0) cout << result[i] << 'p';
                else cout << result[i];
            }
            else {
                if (i%2 != 0) cout << " + " << result[i] << 'p';
                else cout << " + " << result[i];
            }
        }
    }
    cout << endl;
}
 
void moneda(uint idx, int valor, const int x, VI& valors, VI& result) {
    if (valor == x) escribir(result, idx, x);
    else if (idx < 2*valors.size()) {
        if (valor < x) {
            result[idx] = valors[idx/2];
            valor += valors[idx/2];
            moneda(idx + 1, valor, x, valors, result);
            valor -= valors[idx/2];
            result[idx] = 0; // restablecemos el valor original
            moneda(idx + 1, valor, x, valors, result);
        }
    }
}
 
int main () {
    int x, n;
    while (cin >> x >> n) {
        VI valors(n);
        for (int m = 0; m < n; m++) cin >> valors[m];
        sort(valors.begin(), valors.end());
        VI result(2*n);
        moneda(0, 0, x, valors, result);
        cout << "----------" << endl;
    }
}