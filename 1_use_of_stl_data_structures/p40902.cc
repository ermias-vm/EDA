#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string,int> casino;
	string name, op;
	while (cin >> name >> op){
		map<string,int>::iterator it = casino.find(name);
		if (op == "enters") {
			if(it != casino.end()) cout << name << " is already in the casino" << endl;
			else casino.insert(make_pair(name,0));
		}

		else if (op == "wins") {
			int x; cin >> x;
			if (it == casino.end()) cout << name << " is not in the casino" << endl;
			else casino[name] += x;
		}

		else {
			if(it == casino.end()) cout << name << " is not in the casino" << endl;
			else {
				cout << name << " has won " << casino[name] << endl;
				casino.erase(it);
			}
		}
	}
	cout << "----------" << endl;
	for (auto it : casino) cout << it.first << " is winning " << it.second << endl;

}