#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

struct jugador {
    string nom;
    int elo;
};

bool comp(jugador a, jugador b) {
    if (a.elo != b.elo ) return a.elo > b.elo;
    return a.nom < b.nom;

}

int main() {
    unordered_map<string, pair<bool,int>> info;
    string op, jg1;
    while (cin >> op >> jg1) {
        auto it = info.find(jg1);
        if (op == "LOGIN") {
            if(it == info.end()) info[jg1].second = 1200;
            info[jg1].first = true;

        }

        else if (op == "LOGOUT") {
            if (it != info.end()) info[jg1].first = false;
        }

        else if (op == "PLAY") {
            string jg2; cin >> jg2;
            auto it2 = info.find(jg2);
            if (it == info.end() or it2 == info.end() or info[jg1].first == false 
            or info[jg2].first == false)  cout << "jugador(s) no connectat(s)" << endl;
			else {
				info[jg1].second += 10;
				if (info[jg2].second > 1200) info[jg2].second -= 10;
            }
        }
        // cas op == "GET_ELO"
        else  cout << jg1 << ' ' << info[jg1].second << endl;
    }
        
    //vector de jugadors
    vector<jugador> v(info.size());
    auto it = info.begin();
    for(int i = 0; i < info.size(); ++i) {
        v[i].nom = it->first;
        v[i].elo = it->second.second;
        ++it;
    }

    sort(v.begin(), v.end(), comp);
    cout << endl << "RANKING" << endl;
    for (int i = 0; i < v.size(); ++i) cout << v[i].nom << ' ' << v[i].elo << endl;
}