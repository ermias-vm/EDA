#include <iostream>
#include <vector>
#include <map>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;


int k_esim(int k, const VVI& V){
    map<int,int> min;
    for(int i = 0; i < V.size(); ++i) if(!V[i].empty()) min[V[i][0]] = i;
    pair<int,int> res;
    VI it(V.size(), 1); //contador de los elementos visitados de V[0..n] []
    
    while(k > 0){
        res.first = min.begin()->first;
        res.second = min.begin()->second;
        if(V[res.second].size() > it[res.second]) 
            min[V[res.second][it[res.second]++]] = res.second;
        min.erase(min.begin());
        --k;
    }
    return res.first;
}
/*
int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > V(n);
    for (int i = 0; i < n; ++i) {
        int m; cin >> m; //elements fila
        V[i] = vector<int>(m);
        for (int j = 0; j < m; ++j) cin >> V[i][j];
    }
    cout << k_esim(k,V);
}
*/