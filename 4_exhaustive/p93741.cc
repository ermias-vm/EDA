#include <iostream> //NO RESOLT
#include <vector>
#include <set>
#include <string>

using namespace std;

typedef vector<string> VS;

bool satisfiesClauses(const vector<vector<string>>& clauses, const VS& solution) {
    for (const auto& clause : clauses) {
        bool isClauseSatisfied = false;
        for (const auto& literal : clause) {
            bool isNegated = (literal[0] == '-');
            string variable = (isNegated ? literal.substr(1) : literal);
            if ((isNegated && solution[stoi(variable)] == "fals") || (!isNegated && solution[stoi(variable)] == "cert")) {
                isClauseSatisfied = true;
                break;
            }
        }
        if (!isClauseSatisfied) {
            return false;
        }
    }
    return true;
}

void findAllSolutions(const vector<vector<string>>& clauses, const VS& variables, VS& solution, int variableIndex, set<VS>& solutions) {
    if (variableIndex == variables.size()) {
        if (satisfiesClauses(clauses, solution)) {
            solutions.insert(solution);
        }
        return;
    }
    solution[stoi(variables[variableIndex])] = "cert";
    findAllSolutions(clauses, variables, solution, variableIndex + 1, solutions);
    solution[stoi(variables[variableIndex])] = "fals";
    findAllSolutions(clauses, variables, solution, variableIndex + 1, solutions);
    solution[stoi(variables[variableIndex])] = "-";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<string>> clauses(n, vector<string>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> clauses[i][j];
        }
    }
    VS variables(m);
    for (int i = 0; i < m; i++) {
        variables[i] = to_string(i);
    }
    VS solution(m, "-");
    set<VS> solutions;
    findAllSolutions(clauses, variables, solution, 0, solutions);
    for (const auto& sol : solutions) {
        for (const auto& val : sol) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
