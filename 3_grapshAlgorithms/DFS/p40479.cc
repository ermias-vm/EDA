#include <iostream>
#include <vector>
using namespace std;
typedef vector<pair<int,int>> VP;
VP dirs = {{0,1},{0,-1},{1,0},{-1,0}};
typedef vector<vector<char>> Matriu;



void pintar(Matriu& M, int i, int j,char c) {
    M[i][j] = c;
    for(auto d : dirs) {
        int v_i = i + d.first;
        int v_j = j + d.second;
        if (M[v_i][v_j] == '.') pintar(M,v_i,v_j,c);
    }
}


int main() {
    int n,m; 
    while (cin >> n >> m) { 
        Matriu M(n,vector<char>(m));
        VP pos_lletra; //vector de posicions a pintar
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j) {
                cin >> M[i][j];
                if (M[i][j] != '#' && M[i][j] != '.') pos_lletra.push_back({i,j});  
            }
        }
        for (auto x : pos_lletra) pintar(M,x.first,x.second,M[x.first][x.second]);
        //escriu matriu
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cout << M[i][j];
            cout << endl;
        }
        cout << endl;
    }
}