// reines (2)


#include <iostream>
#include <vector>
using namespace std;

using VB = vector<bool>;
int n;
vector<int> posReinas;
VB colum, dia1, dia2;


void escriu() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cout << (j == posReinas[i] ? 'Q' : '.');
    cout << endl;
  }
  cout << endl;
}


void combinacions (int fila ) {
    if (fila  == n) escriu();
    for(int col = 0; col < n; ++col) {
        int d1 = fila +col, d2 = fila - col + n-1;
        if (!colum[col] and !dia1[d1] and !dia2[d2])  {
            colum[col] = dia1[d1] = dia2[d2] = true;
            posReinas[fila] = col;
            combinacions(fila +1);
            colum[col] = dia1[d1] = dia2[d2] = false;
        }   
    }
}

int main() {
    cin >> n;
    colum = VB(n,false);
    posReinas = vector<int>(n);
    dia1 = dia2 = VB(2*n-1,false);
    combinacions(0);
}