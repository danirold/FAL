// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSol {
    vector<int> sol;
    int sumaSatisf;
};

void resolver(int const& num_juguetes, vector<vector<int>> const& satisf, int k, tSol & sol, vector<bool> & marcas, int & satisMejor, vector<int> const& acum) {
    for (int i = 0; i < num_juguetes; ++i) {
        sol.sol[k] = i;
        if (!marcas[i]) {
            marcas[i] = true;
            sol.sumaSatisf += satisf[k][i];
            if (k == sol.sol.size() - 1) {
                if (sol.sumaSatisf > satisMejor)
                    satisMejor = sol.sumaSatisf;
            }
            else {
                if (sol.sumaSatisf + acum[k + 1] > satisMejor) 
                    resolver(num_juguetes, satisf, k + 1, sol, marcas, satisMejor, acum);
            }
            marcas[i] = false;
            sol.sumaSatisf -= satisf[k][i];
        }
    }
}

bool resuelveCaso() {
    int num_juguetes; int num_ninos;
    cin >> num_juguetes >> num_ninos;

    if (!std::cin)
        return false;

    vector<vector<int>> satisf(num_ninos, vector<int> (num_juguetes));
    for (int i = 0; i < num_ninos; ++i) {
        for (int j = 0; j < num_juguetes; ++j) cin >> satisf[i][j];
    }

    vector<int> acum(num_ninos);
    for (int i = 0; i < num_ninos; ++i) {
        int auxMax = satisf[i][0];
        for (int j = 1; j < num_juguetes; ++j)
            if (auxMax < satisf[i][j]) auxMax = satisf[i][j];
        acum[i] = auxMax;
    }
    for (int i = acum.size() - 1; i > 0; --i) {
        acum[i - 1] += acum[i];
    }

    int satisMejor = 0;
    for (int i = 0; i < num_ninos; ++i) {
        satisMejor += satisf[i][i];
    }

    tSol s;
    s.sol.assign(num_ninos, 0);
    s.sumaSatisf = 0;
    vector<bool> marcas(num_juguetes, false);
    resolver(num_juguetes, satisf, 0, s, marcas, satisMejor, acum);
    cout << satisMejor << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}