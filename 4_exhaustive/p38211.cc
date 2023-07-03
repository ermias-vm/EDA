// reines (3)

#include <iostream>
#include <vector>
using namespace std;

using VB = vector<bool>;
int n;
vector<int> posReinas;
VB colum, dia1, dia2;


void escriu() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << (j == posReinas[i] ? 'Q' : '.');
        cout << endl;
    }
}


bool combinacions (int fila ) {
    if (fila == n) {
        escriu();
        return true;
    }
    for(int col = 0; col < n; ++col) {
        int d1 = fila +col, d2 = fila - col + n-1;
        if (!colum[col] and !dia1[d1] and !dia2[d2])  {
            colum[col] = dia1[d1] = dia2[d2] = true;
            posReinas[fila] = col;
            if (combinacions(fila + 1)) return true;
            colum[col] = dia1[d1] = dia2[d2] = false;
        }   
    }
    return false;
}

int main() {
    cin >> n;
    if ( n > 1 and n < 4) cout << "NO SOLUTION" << endl;
    else {
        colum = VB(n,false);
        posReinas = vector<int>(n);
        dia1 = dia2 = VB(2*n-1,false);
        combinacions(0);
    } 
}