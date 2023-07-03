#include <iostream>
#include <set>
using namespace std;

int main() {
	set<string> s;
	string word; cin >> word;
    s.insert(word);
	auto it = s.begin();
	
	while (word != "END") {
		if (s.size()%2==0 and word < *it) --it;
		else if (s.size()%2!=0 and word > *it) ++it;
		cout << *it << endl;
        cin >> word;
        auto it = s.insert(word);
	}
}