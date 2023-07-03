#include <iostream>
#include <vector>

using namespace std;


int bs(const vector<double>& v, int left, int right, double x){
	if(left>right) return -1;
	int m=(left+right)/2;
	if(v[m]<x) return bs(v,m+1,right,x);
	if(v[m]>x) return bs(v,left,m-1,x);
	if (m-1 < left or v[m-1] != x) return m;
    return bs(v,left,m-1,x);
}

int first_occurrence(double x, const vector<double>& v){
	return bs(v, 0,v.size()-1,x);
}

/*
int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}
*/