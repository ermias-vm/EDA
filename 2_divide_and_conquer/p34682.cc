#include <iostream>
#include <vector>
using namespace std;

int buscar (vector<int>& S, int esq, int dre, int a) {
    
    if (esq > dre) return -1; // Error o són iguals
    int mig = (dre+esq)/2;
    //mig === 0 para el caso de f(1) = 1 i mig != S[mig-1]+a) para 
    if (S[mig]+a == mig+1 and (mig -1 < esq or mig != S[mig-1]+a)) return mig+1;
    else if (S[mig]+a < mig+1) return buscar(S, mig+1, dre, a);
    else return buscar(S, esq, mig-1, a);
}


int main() {
    int index = 0, n;
    while(cin >> n){
        cout << "Sequence #" << ++index << endl;
        vector<int> v(n);
        for (int i  = 0; i < n; i++) cin >> v[i];
        int m; cin >> m;
        for (int i = 0; i < m; i++){
            int a;
            cin >> a;
            
            int resultat = buscar(v, 0, v.size()-1, a);
            
            if (resultat != -1) cout << "fixed point for " << a << ": " << resultat << endl;
            else cout << "no fixed point for " << a << endl;
        }
        cout << endl;
    } 
}
