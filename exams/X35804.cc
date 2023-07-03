 #include <iostream>
 #include <map>
 using namespace std;
 
 
 struct Info {
   string code;
   int price;
 };
 
 
int main() {
    map<int, Info> M;
    char c;
    while (cin >> c) {
        if (c == 'n') {// Escriu el nombre de creuers emmagatzemats precedit de “num:”.
            cout << "num: " << M.size() << endl;
        }
        else if (c == 'u') { //introduir creuer si, existeix acutalitza  dades
            string code;
           int length, price;
           cin >> code >> length >> price;
            M[length] = {code,price};
        }
         else if (c == 'q') { //Consulta el preu del creuer que té durada ℓ. Si no n’hi ha cap, escriu -1.
        int length;
        cin >> length;
        auto it = M.find(length);
        if(it == M.end()) cout << -1 << endl;
        else cout << it->second.price << endl;
        }
        else if (c == 'p') {
            cout << string(10, '-') << endl; //lista de creuers  escriu : codi , durada , preu
            for (auto x : M) cout << x.second.code << ' ' << x.first << ' ' << x.second.price << endl;
            cout << string(10, '*') << endl;
        }
        else { // c == ’s’ // info creuer amg la segona durada mes curta ; si no existeix escriu : no
            if (M.size() <2) cout << "no" << endl;
            else {
                auto it = M.begin(); ++it;
                cout << it->second.code << ' ' << it->first << ' ' << it->second.price << endl;
            } 
        }
    }
}