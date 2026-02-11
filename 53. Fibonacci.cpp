// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSol {
    long long int n1;
    long long int n2;
};

tSol resolver(int n) {
    tSol sol;
    if (n == 0) {
        sol.n1 = 0;
        sol.n2 = 0;
    }
    else if (n == 1) {
        sol.n1 = 1;
        sol.n2 = 0;
    }
    else {
        sol = resolver(n - 1);
        long long int aux = sol.n2;
        sol.n2 = sol.n1;
        sol.n1 = sol.n1 + aux;
    }
    return sol;
}

bool resuelveCaso() {
    int num; cin >> num;

    if (!std::cin)
        return false;

    cout << resolver(num).n1 << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}