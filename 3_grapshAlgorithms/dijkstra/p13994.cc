//Dijkstra (path)
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

int  MAX = INT_MAX; // MAX = maxim valor representable en un int
int n;
using VVP = vector<vector<pair<int,int>>>;

void create_path(vector<int>& path,vector<int>& previ,int ini, int fi) {
    while (fi != ini) {
        path.push_back(fi);
        fi = previ[fi];
    }
    path.push_back(ini);
    reverse(path.begin(),path.end());
}

int dijkstra(const VVP& G, vector<int>& path ,int ini, int fi) {
    vector<int> distancia(n,MAX); 
    vector<int> previ(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    distancia[ini] = 0;
    q.push({0,ini});
    while (!q.empty()){
        pair<int,int> u = q.top(); q.pop(); //first = pes arc del node second = node
        if(u.first == distancia[u.second]){ // nomes s'executen nodes amb la menor distancia
            if (u.second == fi) {
                create_path(path,previ,ini,fi);
                return u.first;
            }
            for (auto v : G[u.second]) {
                int dist_v = u.first + v.first;
                if(dist_v < distancia[v.second]) {
                    distancia[v.second] = dist_v;
                    previ[v.second] = u.second;
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
        vector<int> path;
        int dist = dijkstra(G,path,ini,fi);
        if (dist == -1) cout << "no path from " << ini << " to " << fi << endl;
        else {
            if (path.size() == 1) cout << ini << endl;
            else {
                for(int i = 0; i < path.size() -1 ; ++i) cout << path[i] << ' ';
                cout << path[path.size()-1] << endl;
            }
        }
    }
}