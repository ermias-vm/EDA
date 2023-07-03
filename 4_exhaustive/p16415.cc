// reines (1)

#include <iostream>
#include <vector>
using namespace std;
using VB = vector<bool>;
int n;
VB colum,dia1,dia2;

int combinacions (int fila ) {
    if (fila  == n) return 1;
    int res = 0;
    for(int col = 0; col < n; ++col) {
        int d1 = fila +col, d2 = fila - col + n-1;
        if (!colum[col] and !dia1[d1] and !dia2[d2])  {
            colum[col] = dia1[d1] = dia2[d2] = true;
            res += combinacions(fila +1);
            colum[col] = dia1[d1] = dia2[d2] = false;
        }   
    }
    return res;
}

int main() {
    cin >> n;
    colum = VB(n,false);
    dia1 = dia2 = VB(2*n-1,false);
    cout << combinacions(0) << endl;
}