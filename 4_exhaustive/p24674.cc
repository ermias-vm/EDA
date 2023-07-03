// permutacions de paraules


#include <iostream>
#include <vector>
using namespace std;

using VS = vector<string>;
using VI = vector<int>;
using VB = vector<bool>;


void escriu(const VS& words,const VI& perm) {
    cout << '(';
    for (uint i = 0; i < perm.size();++i) {
        if (i > 0) cout << ',';
        cout << words[perm[i]];
    }
    cout << ')' <<  endl;
}

void generarPerms(const VS& words,VI &perm,VB& usat, uint idx) {
    if (idx == words.size()) escriu(words,perm);
    else {
        for(uint x = 0; x < words.size(); ++x) {
            if (!usat[x]) {
                usat[x] = true;
                perm[idx] = x;
                generarPerms(words,perm,usat,idx+1);
                usat[x] = false;
            }
        }
    }
}

void permutacions(const VS& words,uint n) {
    VB usat(n,false);
    VI perm(n);
    generarPerms(words,perm,usat,0);
}



int main() {
    int n; cin >> n;
    VS words(n);
    for (string& s : words) cin >> s;
    permutacions(words,n);
}
