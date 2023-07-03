#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre) {
    while (esq <= dre) {
        int mid = (esq + dre)/2;
        if (v[mid] == x) return mid;
        if (v[mid] < x) return posicio(x,v,mid + 1,dre);
        return posicio(x,v,esq,mid - 1);
    }
    return -1;
}