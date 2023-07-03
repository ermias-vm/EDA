#include <iostream>
#include <map>
using namespace std;

int main() {
    cout.setf(ios::fixed);
	cout.precision(4);

    map<int,int> m;
    string op;
    double total = 0, elements = 0;

    while (cin >> op) {
        if (op == "number") {
            int num; cin >> num;
            total += num;
            ++elements;
            auto it = m.find(num);
            if (it == m.end()) m.insert(make_pair(num,1));
            else it->second ++;
        }
        else if (!m.empty()) {
            auto it = m.begin();
            total -= it->first;
            it->second --;
            if (it->second < 1) m.erase(it);
            --elements;
        }

        if(m.empty()) cout << "no elements" << endl;
        else {
            auto it = m.begin();
            cout << "minimum: " << it->first << ", maximum: ";
            it = m.end(); --it;
            cout << it->first << ", average: " << total/elements << endl;
        }

    }

}