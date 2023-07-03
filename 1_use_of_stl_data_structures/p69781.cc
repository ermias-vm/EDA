#include <iostream>
#include <map>
using namespace std;

int main() {
    int y,x,n;



    while (cin >> x >> y >> n) {
        map<int,int> m;
        int ciclo = 0;
        bool trobat = false;
        map<int, int>::const_iterator it;
        m.insert(make_pair(n,ciclo));

        while (not trobat and n <= 100000000) {
            ++ciclo;
            if (n%2 == 0) n = n/2 + x;
            else n = 3*n + y;

            it = m.find(n);
            if(it == m.end()) m.insert(make_pair(n,ciclo));
            else trobat = true;
        }

        if (trobat) cout << m.size() - it->second << endl;
        else cout << n << endl;

    }
    
}