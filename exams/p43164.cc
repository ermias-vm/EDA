//Tresors en un mapa (5) BFS (2n tresor mes proper) // jutge incorrecte mail albert
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using Map = vector<vector<char>>;
const vector<pair<int,int>> dirs = {{0,-1},{0,1},{1,0},{-1,0}};
int f, c; 

bool pos_valida(const Map& M, int i, int j){
    return i >= 0 and i < f and j >= 0 and j < c && M[i][j] != 'X';
}

int segona_distancia_tresor(const Map& M, int i_ini, int j_ini) {
    vector<vector<int>> dist(f,vector<int>(c,-1));
    dist[i_ini][j_ini] = 0;
    queue<pair<int,int>> Q;
    Q.push({i_ini,j_ini});
    vector<int> distTresors;
    while (!Q.empty()) {
        pair<int,int> u = Q.front(); Q.pop();
        for(auto d : dirs) {
            int i = u.first + d.first;
            int j = u.second + d.second;
            if(pos_valida(M,i,j) && dist[i][j] == -1) {
                Q.push({i,j});
                dist[i][j] = dist[u.first][u.second] + 1;
                if (M[i][j] == 't') distTresors.push_back(dist[i][j]);
            }
        }
    }
    if (distTresors.size() < 2) return -1;   
    else return distTresors[distTresors.size()-2];
}

int main() {
    cin >> f >> c;
    Map M(f,vector<char>(c));
    for (int i = 0; i < f; ++i)
        for (int j = 0; j < c; ++j) cin >> M[i][j];
    int f_ini, c_ini; cin >> f_ini >> c_ini;
    int dist = segona_distancia_tresor(M,f_ini - 1, c_ini -1);
    if (dist == -1) cout << "no es pot arribar a dos o mes tresors" << endl;
    else cout << "segona distancia maxima: " << dist << endl;
}
