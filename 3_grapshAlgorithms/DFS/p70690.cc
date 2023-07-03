//Tresors en un mapa(1)
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
typedef vector<vector<char>> Map;

bool vei_ok(Map& M, int i, int j) {
    return i >= 0 and i < int(M.size()) and j >= 0 and j < int(M[0].size()) and M[i][j] != 'X';
}

bool camiTresor(Map& M, int i, int j) {
    if (M[i][j] == 't') return true;
    M[i][j] = 'X';
    for(auto d : dirs) {
        int v_i = i + d.first;
        int v_j = j + d.second;
        if (vei_ok(M,v_i,v_j) and camiTresor(M,v_i,v_j)) return true;
    }
    return false;
}


int main() {
    int n,m; cin >> n >> m; //llegir files i columnes del mapa
    Map map(n,vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> map[i][j];
    int f, c; cin >> f >> c; // llegir fila i columna inicial
    if (camiTresor(map,f-1,c-1)) cout  << "yes" << endl;
    else cout << "no" << endl;
}