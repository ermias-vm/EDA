#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> Graph;

bool es_cicle (const Graph& g, int u, vector<bool>& visitat, int v_ant) { 
    if (visitat[u]) return true;
    visitat[u] = true;
    //només es crida a es cicle si el vertex actual es diferent al  vertex anterior
    for (int adj : g[u]) if(adj != v_ant && es_cicle(g,adj,visitat,u)) return true;
    return false;
}

int n_arbres(const Graph& g) {
    int n_arb = 0;
    vector<bool> vis(g.size(), false);
    for (int u = 0; u < g.size(); u++) {
        if(!vis[u]) {
            if(es_cicle(g,u,vis,-1)) return -1;
            ++n_arb;
        }
    }
    return n_arb;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        int u, v;
        while (m--){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int arbres = n_arbres(G);
        if (arbres == -1) cout << "no" << endl;
        else cout << arbres << endl;
    }
}