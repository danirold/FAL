// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void escribirSol(vector<char> const& sol) {
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i];
    }
    cout << '\n';
}

void VA(int const& m, vector<char>& sol, int k, char primero) {
    for (char i = primero; i < 'a' + m; ++i) {
        sol[k] = i;
        if (k == sol.size() - 1) {
            escribirSol(sol);
        }
        else VA(m, sol, k + 1, i + 1);
    }
}

bool resuelveCaso() {
    int m; int n; 
    cin >> m >> n;

    if (!std::cin)
        return false;

    vector<char> sol(n);

    VA(m, sol, 0, 'a');
    
    cout << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}