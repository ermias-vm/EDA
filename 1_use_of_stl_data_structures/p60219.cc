#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
struct compare {
    bool operator()(const string& a, const string& b) {
        if (a.length() == b.length()) return a < b;
        return a.length() < b.length();
    }
};

int main() {
    set<string> in; // set of the current words
    set<string,compare> del;  //set of deleted words

    int game = 1; 
    bool quit = false, first = true;
    string w; cin >> w;
 
    while (not quit){
        while (w != "END" and w != "QUIT") {
            if (in.count(w)) {
                in.erase(w);
                del.insert(w);   
            }
            else {
                in.insert(w);
                del.erase(w);
            }
            cin >> w;
        }

        if (not first) cout << endl; //endl entre 1r i 2n joc
        first = false;

        cout << "GAME #" << game << endl << "HAS:" << endl;
        for (auto it : in) cout << it << endl;
        cout << endl << "HAD:" << endl;
        for (auto it : del) cout << it << endl;

        //buidar els dos sets per al seguent joc
        ++game;
        in.erase(in.begin(), in.end());
        del.erase(del.begin(), del.end());

		if (w == "QUIT") quit = true;
		else cin >> w;
    }
}