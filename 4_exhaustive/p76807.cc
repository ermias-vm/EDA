// Sudoku


#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;


void print(const VVI& S) {
    cout << endl;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)cout << (j ? " " : "") << S[i][j];
        cout << endl;
  }
}

bool f(int i, int j,VVI& S,VVB& fila, VVB& colu,VVVB& quad) {
    if (i == 9) { // s'ha finalitzat l'ultima fila del sudoko
        print(S);
        return true;
    }
    if (j == 9) return f(i + 1, 0,S,fila,colu,quad);//saltar a la seguent fila
    if (S[i][j] != 0) return f(i, j + 1,S,fila,colu,quad); // seguent si la cel·la ja esta visitada
    for (int x = 1; x < 10; ++x)
        if (not fila[i][x] and not colu[j][x] and not quad[i/3][j/3][x]) {
            fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
            S[i][j] = x;
            if (f(i, j + 1,S,fila,colu,quad)) return true;
            S[i][j] = 0;
            fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = false;
        }
    return false;
}

int main() {
    int t; cin >> t; cout << t << endl;
    VVI S(9, VI(9));
    VVB fila, colu;
    VVVB quad;
    for (int r = 0; r < t; ++r) {
        VVB fila, colu;
        fila = colu = VVB(9, VB(10, false));
        VVVB quad(3, VVB(3, VB(10, false)));
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                char c; cin >> c;
                if (c == '.') S[i][j] = 0;
                else {
                int x = c - '0';
                S[i][j] = x;
                fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
            }
        }
        f(0, 0,S,fila,colu,quad);
    }
}