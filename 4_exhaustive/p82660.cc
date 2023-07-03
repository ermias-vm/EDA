//Sumes iguals (2)
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

bool escriu_subcjt_rec (const vector<int>&v, int s, vector<bool>& chosen, uint idx, int suma_parcial) {
	if (idx == chosen.size()) {
		if (suma_parcial == s) {
            escriu(v,chosen);
            return true;
        }
        return false;
	}
 	else { 
    	chosen[idx] = true;
        bool trobat = escriu_subcjt_rec(v,s,chosen,idx+1,suma_parcial+ v[idx]);
        if (!trobat) {
    	    chosen[idx] = false;
    	    return escriu_subcjt_rec(v,s,chosen,idx+1,suma_parcial);
        }
        return true;
  	}
}

bool escriu_subcjt (const vector<int>&v, int s) {
  	vector<bool> chosen(v.size());
  	int idx = 0;
  	int suma_parcial = 0;
  	return escriu_subcjt_rec(v,s,chosen,idx,suma_parcial);
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