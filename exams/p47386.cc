#include<iostream>
#include<string>
#include<map>
using namespace std;


int main() {
    string s;
    map<string, string> liats;
    map<string, string>::iterator it;
    while (cin >> s) {
        if (s == "info") {
            cout << "PARELLES:" << endl;
            for (it = liats.begin(); it != liats.end(); ++it) {
                if (it->second != "" && it->first < it->second) {
                    cout << it->first << " " << it->second << endl;
                }
            }
            cout << "SOLS:" << endl;
            for (it = liats.begin(); it != liats.end(); ++it) {
                if (it->second == "") cout << it->first << endl;
            }
            cout << "----------" << endl;
        } 
        else {
            string x, y;
            cin >> x >> y;
            if (liats[x] != "")  liats[liats[x]] = ""; // si x ja esta relacionat; la parella x passa a estar sola
            if (liats[y] != "") liats[liats[y]] = ""; // si y ja esta relacionat; la parella y passa a estar sola
            liats[x] = y;   //es guarden les dos relacios en el map x-y i y-x
            liats[y] = x;
        }
    }
}