#include <iostream>
#include <vector>
using namespace std;
int topPos(const vector<int>& v, int left, int right) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (v[mid] < v[mid + 1]) left = mid + 1;
        else right = mid;
    }
    return left;
}
bool bsIncreas (int x, const vector<int>& v, int left, int right ) {
    if (left > right) return false;
    int mid = (left + right)/2;
    if (v[mid] < x) return bsIncreas(x,v,mid+1,right);
    else if(v[mid] > x) return bsIncreas(x,v,left,mid-1);
    return true;
}
bool bsDecreas (int x, const vector<int>& v, int left, int right ){
    if (left > right) return false;
    int mid = (left + right)/2;
    if (v[mid] > x) return bsDecreas(x,v,mid+1,right);
    else if(v[mid] < x) return bsDecreas(x,v,left,mid-1);
    return true;
}
bool search(int x, const vector<int>& v){
    int j = topPos(v,0,v.size()-1);
    if (v[j] < x) return false;
    return bsIncreas(x,v,0,j) or bsDecreas(x,v,j+1,v.size()-1);
}

/*
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int x;
    while (cin >> x) {
      cout << search(x, v) << endl;
    }
}
*/










