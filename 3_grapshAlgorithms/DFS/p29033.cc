#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> Graph;

bool colorIgual(const Graph& g, int u, vector<int>& color, int color_ant){
    // 0 = no visitat , color1 = 1 (3-2), color2 = 2 (3-1)
    if (color[u]) return color[u] == color_ant; // si el node ja estava visitat
    color[u] = 3-color_ant;
    for(int x : g[u]) if(colorIgual(g,x,color,color[u])) return true;
    return false;
}

bool dosColorajable(const Graph& g){
    vector<int> color(g.size(),0); 
    for(int u = 0; u < g.size(); ++u) if (!color[u] && colorIgual(g,u,color,2)) return false;
    return true;
}

int main(){
    int n,m,u,v;
    while(cin >> n >> m) {
        Graph G(n);
        while (m--){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if (dosColorajable(G)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
