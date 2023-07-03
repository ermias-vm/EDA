#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

int idx (char a, const vector<char>& esp) {
    for (uint i = 0; i < esp.size(); ++i) {
        if (esp[i] == a) return i;
    }
    assert(false); // No hi hauria d'arribar mai
    return -1; 
}

void escriu_permutacions ( const vector<char>& esp,const vector<vector<bool>>& incomp,vector<int>& sol,int idx,vector<bool>& usat) {
    if (idx== int(sol.size())) {
        for (int i : sol) cout << esp[i];
        cout << endl;
    }
    else {
        for (uint i = 0; i < esp.size(); ++i) {
            if (not usat[i] and (idx == 0 or  not incomp[i][sol[idx-1]]) ) {	
	            sol[idx] = i;
	            usat[i] = true;
	            escriu_permutacions(esp,incomp,sol,idx+1,usat);
	            usat[i] = false;
            }
        }   
    }
}
			 

void escriu_permutacions ( const vector<char>& esp,
			   const vector<vector<bool>>& incomp) {
  vector<int> sol(esp.size());
  vector<bool> usat(esp.size(),false);
  int idx = 0;
  escriu_permutacions(esp,incomp,sol,idx,usat);
}

int main ( ){
  int n; cin >> n;
  vector<char> esp(n);
  for (int i = 0; i < n; ++i) cin >> esp[i];
  
  int m; cin >> m;
  vector<vector<bool>> incomp(n,vector<bool>(n,false));
  for (int i = 0; i < m; ++i) {
    char A, B; cin >> A >> B;
    int idxA = idx(A,esp); // Si volem estalviar-nos aquest treball, podem crear una matriu i indexar-la pel codi ASCII
    int idxB = idx(B,esp);
    incomp[idxA][idxB] = true; 
    incomp[idxB][idxA] = true;
  }

  escriu_permutacions(esp,incomp);
}