// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void resolver(vector<int>& v) {
    sort(v.begin(), v.end());
    int buenos = 1;
    int repetido = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] != repetido) {
            v[buenos] = v[i];
            buenos++;
            repetido = v[i];
        }
    }
    v.resize(buenos);
    for (int i = 0; i < buenos; ++i) cout << v[i] << ' ';
    cout << '\n';
}

bool resuelveCaso() {
    int num_elementos;
    cin >> num_elementos;

    if (!std::cin)
        return false;

    vector<int> vector1(num_elementos);
    for (int i = 0; i < vector1.size(); ++i) cin >> vector1[i];
    resolver(vector1);

    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}