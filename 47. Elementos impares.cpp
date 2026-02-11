// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
Recurrencia

T(n) = { c0 caso base
         T(n/2) + c1 caso recursivo
         }

         T(n) = T(n/2) + c1 = T(n/4) + 2c1 = ... = T(n/2^k) + kc1;

         Para k = log2(n)

         T(n) = T(1) + log2 (n) c1 --> O(log n);

*/

int resolver(vector<int> const& v, int ini, int fin) {
    if (ini + 1 == fin) return v[ini];
    else if (ini + 2 == fin) {
        if (v[ini] % 2 == 1) return v[ini];
        else return v[ini + 1];
    }
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] - v[ini] == 2 * (mitad - ini)) return resolver(v, mitad + 1, fin);
        else return resolver(v, ini, mitad + 1);
    }
}

bool resuelveCaso() {
    int num_elem; cin >> num_elem;
    if (num_elem == 0)
        return false;

    vector<int> v(num_elem);
    for (int i = 0; i < v.size(); ++i) cin >> v[i];
    cout << resolver(v, 0, v.size()) << '\n';
    return true;

}

int main() {
    while (resuelveCaso());
    return 0;
}