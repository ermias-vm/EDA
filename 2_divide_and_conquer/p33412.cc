#include <iostream>
#include <vector>

using namespace std;

bool i_resistant_search(double x, const vector<double> &v, int e, int d) {
	int m = (e+d)/2;
	if (d < e) return false;
	if (v[m] == x) return true;
	else if (m > 0 and v[m - 1] == x) return true;
	else if (m < v.size() - 1 and v[m + 1] == x) return true;
	else if (v[m] > x) return i_resistant_search(x, v, e, m - 1);
	else return i_resistant_search(x, v, m + 1, d);
}

bool resistant_search(double x, const vector<double>& v) {
	return i_resistant_search(x, v, 0, int(v.size()-1));
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
            if (resistant_search(x,V)) cout << x << " " << "esta al vector" << endl;
            else cout << x << " " << "no esta al vector" << endl;
        }
    }
}
*/