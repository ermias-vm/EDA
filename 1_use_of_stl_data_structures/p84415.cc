#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	string nom, accio;
	map<string, int> m;
    map<string, int>::const_iterator it;

	while (cin >> accio) {

        if (accio == "minimum?") {
            if (m.empty()) cout << "indefinite minimum" << endl;
            else {
                it = m.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }

        }

        else if (accio == "maximum?") {
            if (m.empty()) cout << "indefinite maximum" << endl;
            else {
                it = m.end(); --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }

        }

        else if (accio == "delete") {
            string word; cin >> word;
            it = m.find(word);

            if (it != m.end()) {
                if (it->second > 1) --m[word];
                else m.erase(word);
            }

	    }

        else {
            string word; cin >> word;
            it = m.find(word);
            if (it == m.end()) m[word] = 1; // word no esta en el map
            else ++m[word];// else m[word] = it->second + 1;
        }
    }
}