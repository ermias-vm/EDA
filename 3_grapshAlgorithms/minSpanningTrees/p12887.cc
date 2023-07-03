#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
typedef pair<int, pair<int,int> > WEdge;
typedef vector< vector< pair<int,int> > > WGraph;
 
void read_graph(WGraph& G, int m) {
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        G[u-1].push_back({w,v-1});
        G[v-1].push_back({w,u-1});
    }
}
 
int MST(const WGraph& G) {
    vector<bool> used(G.size(),false);
    priority_queue<WEdge,vector<WEdge>,greater<WEdge>> Q;
    Q.push({0,{0,0}}); // {peso, {verticeAdyacente,verticeActual}}
    int sum = 0;
 
    while (not Q.empty()) {
        int p = Q.top().first; //peso del vertice actual
        int v = Q.top().second.second; //verice actual
        Q.pop();
        if (not used[v]) {
            used[v] = true;
            sum += p;
            for (uint i = 0; i < G[v].size(); ++i) {
                int w = G[v][i].first;
                int u = G[v][i].second;
                Q.push({w,{v,u}});
            }
        }
    }
    return sum;
}
 
int main () {
    int n, m;
    while (cin >> n >> m) {
        WGraph G(n);
        read_graph(G,m);
        int w = MST(G);
        cout << w << endl;
    }
}