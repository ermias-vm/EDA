//Sumes iguals (1) 
 #include <iostream>
 #include <vector>

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



void escriu_subcjt_rec (const vector<int>&v, int s, vector<bool>& chosen, uint idx, int suma_parcial) {
	if (idx == chosen.size()) {
		if (suma_parcial == s) escriu(v,chosen);
	}
 	else { 
    	chosen[idx] = false;
    	escriu_subcjt_rec(v,s,chosen,idx+1,suma_parcial);
    	chosen[idx] = true;
    	escriu_subcjt_rec(v,s,chosen,idx+1,suma_parcial + v[idx]);
  	} 
}

void escriu_subcjt (const vector<int>&v, int s) {
  	vector<bool> chosen(v.size());
  	int idx = 0;
  	int suma_parcial = 0;
  	escriu_subcjt_rec(v,s,chosen,idx,suma_parcial);
}

int main ( ){
  	int s, n;
  	cin >> s >> n;
  	vector<int> v(n);
  	for (int i = 0; i < n; ++i) cin >> v[i];
  	escriu_subcjt(v,s);
}