#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<vector<int>> Graph;

void bfs(const Graph& graf, int inici) {
    queue<int> q;
    q.push(inici);
    vector<bool> visitat(graf.size(),false);
    while (!q.empty()) {
        int actual  =  q.front(); q.pop();
        if(!visitat[actual]){
            visitat[actual] = true;
            cout << actual << ' ';
            for (int i = 0; i < graf[actual].size(); ++i) {
                q.push(graf[actual][i]);
                //cout <<  '[' << graf[actual][i] << ']'; 
            }    
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m; //llegir número de nodes i arestes
    Graph graf(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; //llegir una arista
        graf[u].push_back(v);
    }
    int inici; cin >> inici;
    bfs(graf,inici);
    cout << endl;
}

/* 
input per a aquest graf de 8 nodes i 8 arestes:

0→1→2→3         / =  2 → 5
↓ ↑/  ↓
4→5→6 7

INPUT:
8 9
0 1
1 2
2 3
2 5
3 7
5 1
0 4
4 5
5 6
0
*/