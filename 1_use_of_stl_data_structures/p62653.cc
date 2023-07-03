#include <iostream>
#include <queue>

using namespace std;

string w;

class comp{
    public:
        bool operator()(string a, string b){
            if(a.length() == b.length()){
                string c = w.substr(0,a.size());
                if(a == c) return false;
                if(b == c) return true;

                if(a < b) return (a < c and c < b);
                else return (!(a > c and c > b));
            }
            else return a.length() > b.length();
        }    
};


int main(){
    while(cin >> w){
        char op;
        string askTicket;
        priority_queue<string, vector<string>, comp> ticketsAsked;
        int tickets = 0;
        while(cin >> op && op != 'E'){
            if(op == 'S'){
                cin >> askTicket;
                ticketsAsked.push(askTicket);
            } else if(op == 'T'){
                ++tickets;
            }
            while(tickets > 0 and (!ticketsAsked.empty())){
                cout << ticketsAsked.top() << endl;
                ticketsAsked.pop();
                --tickets;
            }
        }

        cout << tickets << " ticket(s) left" << endl;
        cout << (ticketsAsked.size()) << " supporter(s) with no ticket" << endl;
        cout << endl;
    }
}
