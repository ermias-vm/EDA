// zeros i uns (2), versio rapida

#include <iostream>
#include <vector>
using namespace std;

void escriu (vector<int>& v) {
    cout << v[0];
    if (v.size() > 1) {
        for (uint i = 1; i < v.size(); ++i) cout << ' ' << v[i];
    }
    cout << endl;
}

void func (uint idx, vector<int>& v, uint nUns, uint u) {
    if (nUns > u or idx - nUns > v.size() - u) return;
    else if (idx == v.size()) {
        if ( nUns == u) escriu(v); 
        return;  
    }
    else {
        v[idx] = 0;
        func(idx+1,v,nUns,u);
        v[idx] = 1; ++nUns;
        func(idx+1,v,nUns,u);
    }
}


int main() {
    int n, u; cin >> n >> u;
    vector<int> v(n);
    func(0,v,0,u);
}


