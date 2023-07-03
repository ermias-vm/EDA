#include <iostream>
#include <vector>

using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;

void escribir(vector<int>& res){
	cout << res[0];//como minimo hay una solucion
	for(uint i=1; i< res.size(); ++i) cout << " " << res[i];
	cout<<endl;
}

void modifGrau(const int tarea,VVI& ady, VI& grau, int x) {
    for (int& y : ady[tarea]) grau[y] += x;
}

void ordTopologica(VVI& ady, VI& grau, VI& res) {
    if(res.size() == grau.size()) escribir(res);
    else {
        for(uint t = 0; t < grau.size(); ++t) {
            if (grau[t] == 0) {
                res.push_back(t); --grau[t];
                modifGrau(t,ady,grau,-1);
                ordTopologica(ady,grau,res);
                ++grau[t];
                modifGrau(t,ady,grau,1);
                res.pop_back();
            }
        }
    }

}

int main() {
    int n,m; cin >> n >> m;
    VVI ady(n);
    VI grau(n,0);
    for(int i = 0; i < m; ++i) {
        int u,v; cin >> u >> v;
        ady[u].push_back(v); //   u  es precedente de toda las tareas  del vector ady[u]
        ++grau[v]; // incrementamos grado de las tareas sucesoras
    }
    VI res;
    ordTopologica(ady,grau,res);
}


