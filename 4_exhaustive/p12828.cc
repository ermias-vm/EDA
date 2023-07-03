// zeros i uns (1)
#include <iostream>
#include <vector>
using namespace std;


void escriu(vector<int>& v) {
  for (uint i = 0; i < v.size(); ++i) {
    if (i > 0) cout << ' ';
    cout << v[i];
  }
  cout << endl;
}

void func(uint indx, vector<int>& v) {
  if (indx == v.size()) escriu(v);
  else {
    v[indx] = 0;
    func(indx + 1,v);
    v[indx] = 1;
    func(indx + 1,v);
  }
}

int main() {
  int n; cin >> n;
  vector<int> v(n);
  func(0,v);
}
