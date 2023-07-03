#include <set>
#include <iostream>
#include <sstream>
using namespace std;


int main() {
    string str;
    while (getline(cin,str)) {
        istringstream ss(str);
        int n , counter = 0;
        set<int> s;
        while (ss >> n) s.insert(n);
        set<int>::iterator it , it_ant;
        it_ant = it = s.begin();
        if (!s.empty()) {
            ++it;
            ++counter;
        }

        for (;it != s.end(); ++it) {
            if(*it_ant < *it and (*it_ant + *it)%2 != 0) ++counter;
            ++it_ant;
        }
        cout << counter << endl;
    }

}