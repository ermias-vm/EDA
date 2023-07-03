
 #include <iostream>
 #include <vector>
 #include <cmath>

using namespace std;
//initial value of reference to non-const must be an lvalue
bool esMultiple (vector<int> v, int x) {
    for (uint i = 0; i < v.size(); ++i) {
        if (x%v[i] == 0) return true;
    }
    return false;
}


void escriuNums (const vector<int>&divisors, int sParcial, int nDigits,int n) {
    if (nDigits == n) cout << sParcial << endl;
    else {
        for (int i = 0; i < 10; ++i) {
            if(!esMultiple(divisors,sParcial*10 + i)) escriuNums(divisors,sParcial*10 + i,nDigits+1,n);
        }
    }
}

int main ( ){
  	int n, m; // n digits m divisors
  	while (cin >>  n >> m) {
  	    vector<int> divisors(m);
  	    for (int i = 0; i < m; ++i) cin >> divisors[i];
        int s = 0; int nDigits = 0;
        escriuNums(divisors,s,nDigits,n);
        cout << "----------" << endl;
    }
}