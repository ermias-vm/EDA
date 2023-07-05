//Tresors en un mapa (4) BFS - versio 2 sense matriu de distancies
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using Map = vector<vector<int>>;
const vector<pair<int,int>> dirs = {{0,-1},{0,1},{1,0},{-1,0}};
int f, c; 
// -2 = 'X'  -3 = 't'   -1 = no visitat   
bool pos_valida(const Map& M, int i, int j){
    return i >= 0 and i < f and j >= 0 and j < c && (M[i][j] == -1 || M[i][j] == -3);
}

int max_distancia_tresor(Map& M, int i_ini, int j_ini) {
    queue<pair<int,int>> Q;
    Q.push({i_ini,j_ini});
    M[i_ini][j_ini] = 0;
    int max_dist = -1;
    while (!Q.empty()) {
        pair<int,int> u = Q.front(); Q.pop();
        for(auto d : dirs) {
            int i = u.first + d.first;
            int j = u.second + d.second;
            if(pos_valida(M,i,j)) {
                Q.push({i,j});
                if (M[i][j] == -3) max_dist = M[u.first][u.second] + 1;
                M[i][j]= M[u.first][u.second] + 1;
            }
        }
    }
    return max_dist;
}

int main() {
    cin >> f >> c;
    Map M(f,vector<int>(c,-1));
    char ch;
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> ch;
            if(ch == 't') M[i][j] = -3;
            else if(ch == 'X') M[i][j] = -2;
        }
    }
    int f_ini, c_ini; cin >> f_ini >> c_ini;
    int dist = max_distancia_tresor(M,f_ini - 1, c_ini -1);
    if (dist == -1) cout << "no es pot arribar a cap tresor" << endl;
    else cout << "distancia maxima: " << dist << endl;
}