//Las Zamburguesas
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
int n; double d; // n = numero de roques;   d = distancia
struct rock {
    double x,y,r;
};

bool dist_valida(rock a, rock b) {
//distancia entre roques = distancia dels centres de les roques - els seur radis
    double x = sqrt(pow((a.x-b.x),2) + pow((a.y-b.y),2))-a.r-b.r;
    return d >= x;
}

int zamburguesas(const vector<rock>& rk) {
    vector<bool> visitat(n,false);
    vector<int> salts (n,0);
    queue<int> q; q.push(0);
    visitat[0] = true;

    while (!q.empty()) {
        int r = q.front(); q.pop();
            for (int i = 1; i < n; ++i) {
                if (r != i && !visitat[i] && dist_valida(rk[r],rk[i])){
                    salts[i] = salts[r] + 1; 
                    if(i == n - 1) return salts[i];
                    q.push(i);
                    visitat[i] = true;

                }
            }
    }
    return -1;
}

int main() {
    while (cin >> n >> d) {
        vector<rock> rk(n);
        for (int i = 0; i < n; i++) cin >> rk[i].x >> rk[i].y >> rk[i].r;
        int res = zamburguesas(rk);
        if (res < 0) cout << "Xof!" << endl;
        else cout << res << endl;
    }   
}