//Sumes iguals (2) (push_back) //no funcina
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void escriu (const vector<int>&v,const vector<bool>& chosen) {
	bool primer = true;
    cout << "{";
    for (uint i = 0; i < v.size(); ++i) {
		if (chosen[i]) {
	    	if (primer) {
				cout << v[i];
				primer = false;
			}
			else cout << "," << v[i];
      	}
	}
	cout << "}" << endl;
}

bool escriu_subcjt_rec(const vector<int>& v, int s, vector<bool>& chosen, int suma_parcial) {
    if (chosen.size() == v.size()) {
        if (suma_parcial == s) {
            escriu(v, chosen);
            return true;
        }
        return false;
    } else {
        chosen.push_back(true);
        bool trobat = escriu_subcjt_rec(v, s, chosen, suma_parcial + v[chosen.size() - 1]);
		chosen.back() = false;
        if (!trobat) {
            chosen.push_back(false);
            return escriu_subcjt_rec(v, s, chosen, suma_parcial);
        }
		chosen.pop_back();
        return true;
    }
}

bool escriu_subcjt (const vector<int>&v, int s) {
  	vector<bool> chosen;
  	int sumParcial = 0;
  	return escriu_subcjt_rec(v,s,chosen,sumParcial);
}

bool cmp(int a, int b) {
    return a > b;
}

int main ( ){
  	int s, n;
  	cin >> s >> n;
  	vector<int> v(n);
  	for (int& x: v) cin >> x;
    sort(v.begin(),v.end(),cmp);
  	if (!escriu_subcjt(v,s)) cout << "no solution" << endl;
}