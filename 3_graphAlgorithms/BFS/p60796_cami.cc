//Tresors en un mapa (2) BFS
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

using Map = vector<vector<char>>;
using  VSP= pair<int,stack<pair<int,int>>>;
using  VP =  vector<pair<int,int>>;
const  VP dirs = {{0,-1},{0,1},{1,0},{-1,0}};
int f, c;

bool pos_valida( const Map& M, int i, int j){
    return i >= 0 and i < f and j >= 0 and j < c && M[i][j] != 'X';
}

stack<pair<int,int>> cami (const pair<int,int>& orig, pair<int,int>& desti,const vector<VP>& prev) {
    stack<pair<int,int>> c;
    while (desti != orig) {
        c.push(desti);
        desti = prev[desti.first][desti.second];
    }
    c.push(orig);
    return c;
}

VSP min_distancia_tresor(const Map& M, int i_ini, int j_ini) {
    vector<vector<int>> dist(f,vector<int>(c,-1));
    vector<VP> prev(f,VP(c,{-1,-1}));
    dist[i_ini][j_ini] = 0;
    queue<pair<int,int>> Q;
    Q.push({i_ini,j_ini});
    while (!Q.empty()) {
        pair<int,int> u = Q.front(); Q.pop();
        for(auto d : dirs) {
            int i = u.first + d.first;
            int j = u.second + d.second;
            if(pos_valida(M,i,j) && dist[i][j] == -1) {
                Q.push({i,j});
                dist[i][j] = dist[u.first][u.second] + 1;
                prev[i][j] = u;
                pair<int,int> desti = {i,j};
                if (M[i][j] == 't')  return {dist[i][j],cami({i_ini,j_ini},desti,prev)};
            }
        }
    }
    return {-1,{}};
}

int main() {
    cin >> f >> c;
    Map M(f,vector<char>(c));
    for (int i = 0; i < f; ++i)
        for (int j = 0; j < c; ++j) cin >> M[i][j];
    int f_ini, c_ini; cin >> f_ini >> c_ini;
    VSP res = min_distancia_tresor(M,f_ini - 1, c_ini -1);
    if (res.first == -1) cout << "no es pot arribar a cap tresor" << endl;
    else {
        cout << "distancia minima: " << res.first << endl;
        while(!res.second.empty()) {
            cout << "(" << res.second.top().first+1 << "," << res.second.top().second+1 << ") ";
            res.second.pop();
        }
        cout << endl;
    }
}


