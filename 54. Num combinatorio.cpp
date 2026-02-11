// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int resolver(int a, int b, vector<vector<int>>& matriz) {
    if (b == 0 || a == b) {
        matriz[a][b] = 1;
    }
    else {
        if (matriz[a - 1][b - 1] == -1) {
            matriz[a - 1][b - 1] = resolver(a - 1, b - 1, matriz);
        }
        if (matriz[a - 1][b] == -1) {
            matriz[a - 1][b] = resolver(a - 1, b, matriz);
        }
        matriz[a][b] = matriz[a - 1][b - 1] + matriz[a - 1][b];
    }
    return matriz[a][b];
}

bool resuelveCaso() {
    int a, b;
    cin >> a >> b;

    if (!std::cin)
        return false;

    vector<vector<int>> matriz(a + 1, vector<int>(b + 1, -1));
    int sol = resolver(a, b, matriz);
    cout << sol << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}