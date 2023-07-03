#include <iostream>
#include <queue>
using namespace std;
void incDrec(priority_queue<int>& q, int op) {
    int x; cin >> x;
    if (q.empty()) cout << "error!" << endl;
    else {
		int aux = q.top(); q.pop();
		q.push(aux+x*op);
    }
}

int main() {
    char c;
    int x;
    priority_queue<int> q;
    while (cin >> c) {
        if (c == 'S') { // Guarda una còpia del número x donat
            cin >> x;
            q.push(x);
        }
        else if (c == 'A') { //Consulta el número més gran
            if (q.empty()) cout << "error!" << endl;
            else cout << q.top() << endl;
        }
        else if (c == 'R') {  // Esborra el número més gran
            if (q.empty()) cout << "error!" << endl;
            else q.pop();
        }
        else if (c == 'I') incDrec(q,1); //Incrementa el número més gran 
        else incDrec(q,-1); // cas c = 'D'; Decrementa el número més gran
    }
}