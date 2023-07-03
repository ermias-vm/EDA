#include <iostream>
#include <vector>
using namespace std;

void InvMerge(vector<int>& v, int l, int m, int r,int& inv) {
    int n1 = m - l + 1;
    int n2 = r - m;
 
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = v[l + i];
    for (int j = 0; j < n2; j++) R[j] = v[m + 1 + j];
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            inv = inv +  L.size()-i;
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(vector<int>& v, int l, int r,int& inv) {
    if (l < r) {
        int m =(l+r)/2;
        mergeSort(v, l, m,inv);
        mergeSort(v, m + 1, r,inv);
        InvMerge(v, l, m, r,inv);
    }
}

/*Count number of inversions using merge sort*/
int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        int inv = 0;
        mergeSort(v,0,n-1,inv);
        cout << inv << endl;
    }
}