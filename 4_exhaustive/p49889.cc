#include <iostream>
#include <vector>
using namespace std;
using VB = vector<bool>;
using VVB = vector<VB>;
using VS = vector<string>;

void permuts(uint idx, int n, VS& chars, string& res, VVB& usat) {
    if (idx == res.size()) cout << res << endl;
    else {
        int type = idx % 2; // type :  0 = consonant 1 = vowel
        for (int i = 0; i < n; ++i) {
            if (!usat[type][i]) {
                res[idx] = chars[type][i];
                usat[type][i] = true;
                permuts(idx + 1, n, chars, res, usat);
                usat[type][i] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    VVB usat(2, VB(n, false));
    VS chars(2);
    cin >> chars[0] >> chars[1]; // chars[0] (consonants); char[1] (vowels)
    string res(2 * n, ' ');
    permuts(0, n, chars, res, usat);
}