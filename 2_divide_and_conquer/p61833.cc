#include <iostream>
#include <vector>
using namespace std;

vector<int> multMod(vector<int> m1, vector<int> m2, int mod) {
    vector<int> res(4);
    res[0] = (m1[0]*m2[0] + m1[1]*m2[2]) % mod; // a*a + b*c
    res[1] = (m1[0]*m2[1] + m1[1]*m2[3]) % mod; // a*b + b*d
    res[2] = (m1[2]*m2[0] + m1[3]*m2[2]) % mod; // c*a + d*c
    res[3] = (m1[2]*m2[1] + m1[3]*m2[3]) % mod; // c*b + d*d
    return res;
}

vector<int> exponentMod(vector<int> m, int n, int mod) {
    if (n == 0) {
        vector<int> id = {1,0,0,1};
        return id;
    }
    else if (n%2 == 1) return multMod(m,exponentMod(m,n-1,mod),mod);
    else {
        vector<int> p = exponentMod(m,n/2,mod);
        return multMod(p,p,mod);
    }
}

int main() {
    /* M  es una matriu  4*4  tal que a = M11, b = M12, c = M21, d = M22
    resultat = M^n mod m */
    int a, b, c, d, n, mod;
    while (cin >> a >> b >> c >> d >> n >> mod) {
        vector<int> M = {a,b,c,d};
        vector<int> Mexp = exponentMod(M,n,mod);
        cout << Mexp[0] << " " << Mexp[1] << endl <<
        Mexp[2] << " " << Mexp[3] << endl << "----------" << endl;
    }
}