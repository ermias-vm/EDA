#include <iostream>
#include <vector>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

void write (int n, int p, const VS& words, const VI& res) {
	for (int j = 0; j < p; ++j) {
        //for(int x = 0; x < res.size();++x) cout << res[x] << ' '; //valores de res en cada subconjunto
		cout << "subconjunt " << j+1 << ": {";
        bool first = true;
		for (int i = 0; i < n; ++i) {
	        if (res[i] == j) {
                if (first) {
                    cout << words[i];
                    first = false;
                }
                else cout << ',' << words[i];
		    }
        }
		cout << "}" << endl;
	}
	cout << endl;
}

void partitions(int idx, int n, int p, const VS& words, VI& res) {
	if (idx == n) write (n, p, words, res );
	else for (int i = 0; i < p; ++i) {
		res[idx] = i ;
		partitions(idx+1, n, p, words, res);
	}
}

int main() {
	int n; cin >> n;
	VS words(n);
	for (auto& x : words) cin >> x;
	int p; cin >> p;
	VI res(n);
	partitions(0, n, p, words, res);
}