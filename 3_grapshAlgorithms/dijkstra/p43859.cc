//Dijkstra
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int  MAX = INT_MAX; // MAX = maxim valor representable en un int
int n;
using VVP = vector<vector<pair<int,int>>>;

int dijkstra(const VVP& G,int ini, int fi) {
    vector<int> distancia(n,MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    distancia[ini] = 0;
    q.push({0,ini});
    while (!q.empty()){
        pair<int,int> u = q.top(); q.pop(); //first = pes arc del node second = node
        if(u.first == distancia[u.second]){ // nomes s'executen nodes amb la menor distancia
            if (u.second == fi) return u.first;
            for (auto v : G[u.second]) {
                int dist_v = u.first + v.first;
                if(dist_v < distancia[v.second]) {
                    distancia[v.second] = dist_v;
                    q.push({dist_v,v.second});
                }
            }
        }
    }
    return -1;
}
int main() {
    int m;
    while (cin >> n >> m){
        VVP G(n);
        int u, v, c;
        while (m--) {
            cin >> u >> v >> c;
            G[u].push_back({c,v});
        }
        int ini, fi; cin >> ini >> fi;
        int dist = dijkstra(G,ini,fi);
        if (dist == -1) cout << "no path from " << ini << " to " << fi << endl;
        else cout << dist << endl;
    }
}