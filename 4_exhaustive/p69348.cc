#include <iostream>
#include <vector>
using namespace std;

using VB = vector<bool>;
using VI = vector<int>;

void print(const VI& v) {
    cout << '(';
    for (uint i = 0; i < v.size(); ++i){
        if (i == 0) cout << v[i];
        else cout << ',' << v[i];
    }
    cout << ')' << endl;
}
void permuts(VI& v, VB& usat, uint idx){
    if (idx == v.size()) print(v);
    for (uint x = 0; x < v.size(); ++x) {
        if (!usat[x]) {
            usat[x] = true;
            v[idx] = x+1;
            permuts(v,usat,idx+1);
            usat[x] = false;
        }
    }
}


int main() {
    int n; cin >> n;
    VI v(n);
    VB usat(n,false);
    permuts(v,usat,0);
}