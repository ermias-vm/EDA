#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        vector<int> grau_e(n,0); //vector de graus entrada
        while (m--) {
            int u,v; cin >> u >> v;
            G[u].push_back(v);
            ++grau_e[v];
        }

        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; ++i) if(grau_e[i] == 0) q.push(i);
        bool primer =  true;
        while(!q.empty()) {
            if(!primer) cout << ' ';
            int  x = q.top(); q.pop();
            for(int y : G[x]) {
                --grau_e[y];
                if (grau_e[y] == 0) q.push(y);
            }
            cout  << x;
            primer = false;
        }
        cout << endl;
    }
}