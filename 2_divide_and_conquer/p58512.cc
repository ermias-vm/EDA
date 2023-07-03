#include <iostream>
using namespace std;

double powers(double x, int n) {
    if (n == 0) return 1;
    double result = 1;
    while (n > 0) {
        if (n % 2 == 1) result *= x;
        x *= x;
        n /= 2;
    }
    return result;
}

int rates(double m, double f, double r, int min, int max) {
    while (min <= max) {
        int mid = (min + max) / 2;
        double bank = powers(r, mid) * m;
        double prof = mid * f + m;
        if (prof > bank) min = mid + 1;
		else if (prof < bank) max = mid - 1;
        else return mid;
    }
    return min;
}

int main() {
	double m, f, r;
	while (cin >> m >> f >> r) cout << rates(m,f,1+r/100,1, 10000000) << endl;
}