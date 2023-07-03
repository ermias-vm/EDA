//Sumes iguals (3) 
 #include <iostream>
 #include <vector>

using namespace std;
using VI = vector<int>;
using VB = vector<bool>;

void escriu (const VI& v,const VB& chosen) {
    cout << "{";
    bool primer = true;
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

void sumes(const VI& v, VB& chosen,const int s, uint idx, int sumPar, int sumRest) {
    if (sumPar > s or sumPar + sumRest < s) return;
    if (idx == v.size()) escriu(v,chosen);
    chosen[idx] = false; sumes(v,chosen,s,idx+1,sumPar,sumRest-v[idx]);
    chosen[idx] = true; sumes(v,chosen,s,idx+1,sumPar+v[idx],sumRest-v[idx]);
}


int main ( ){
  	int s, n;
  	cin >> s >> n;
  	VI v(n);
    int sum = 0;
  	for (int i = 0; i < n; ++i){
        cin >> v[i];
        sum += v[i];
    }
    VB chosen(n);
  	sumes(v,chosen,s,0,0,sum);
}