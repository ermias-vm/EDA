#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
using  Graph = vector<vector<int>> ;

void min_order(const Graph& Tasks, map<string,int>& tasks_pos, const vector<string>& nums, vector<int>& grau_en, vector<string>& order) {
    int n = Tasks.size();
    priority_queue<string, vector<string>, greater<string>> q;
    for (int i = 0; i < n; ++i) if (grau_en[i] == 0) q.push(nums[i]);
    while (!q.empty()) {
        string s = q.top(); q.pop();
        order.push_back(s);
        for (int y : Tasks[tasks_pos[s]]) if (--grau_en[y] == 0) q.push(nums[y]);
    }
}

int main() {
    int n;
    while (cin >> n) {
        map<string, int> tasks_pos;
        vector<string> nums(n);
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            nums[i] = s;
            tasks_pos.insert({s, i});
        }
        int m; cin >> m;
        Graph Tasks(n);
        vector<int> grau_en(n, 0); //vector de graus entrada
        for (int i = 0; i < m; ++i) {
            string x, y;
            cin >> x >> y;
            Tasks[tasks_pos[x]].push_back(tasks_pos[y]);
            ++grau_en[tasks_pos[y]];
        }
        vector<string> order;
        min_order(Tasks,tasks_pos,nums,grau_en,order);
        if (order.size() == nums.size()) {
            for(string x : order) cout << x;
            cout << endl;
        }else cout << "NO VALID ORDERING" << endl;
    } 
}