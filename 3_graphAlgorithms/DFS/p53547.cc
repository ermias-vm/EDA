#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> Board;
typedef vector<pair<int,int>> VP;
const VP dirs = {{-1,-1},{-1,1},{1,-1},{1,1}};

void dfs(Board& B, int i, int j, int& sum_pos, int& n_pos) {
    if (B[i][j] != -1) {
        sum_pos += B[i][j];
        ++n_pos;
        B[i][j] = -1;
        for (auto d : dirs) {
            int di = i + d.first;
            int dj = j + d.second;
            if (di >= 0 and di < int(B.size()) and dj >= 0 and dj < int(B[0].size())) dfs(B,di,dj,sum_pos,n_pos);
        }
    }
}

bool same_avg(Board& B,VP& P,const int avg) {
    for (auto x : P) {
        if (B[x.first][x.second] != -1) {
            int sum_pos = 0, n_pos = 0;
            dfs(B,x.first,x.second,sum_pos, n_pos);
            if (sum_pos/n_pos != avg) return false;
        }
    }
    return true;
}

int main() {
    int n, m, t; cin >> t;
    for (int index = 1; index <= t; ++index) {
        cin >> n >> m;
        VP P; // vector de posiciones
        Board B(n, vector<int>(m));
        int valid_pos = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                string s; cin >> s;
                if (s == "X") B[i][j] = -1;
                else {
                    int num = stoi(s);
                    B[i][j] = num;
                    sum += num; ++valid_pos;
                    P.push_back({i,j});
                }
            }
        }
    
        cout << "Case " << index << ": ";
        if (valid_pos == 0) cout << "yes" << endl;
        else if (sum % valid_pos) cout << "no" << endl;
        else  cout <<  (same_avg(B,P,sum/valid_pos) ? "yes" : "no") << endl;
    }
}