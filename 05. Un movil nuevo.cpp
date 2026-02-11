// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

vector<int> ordenarVectores(vector<int> const& A, vector<int> const& B) {
    vector<int> vectorFinal;

    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            vectorFinal.push_back(A[i]);
            ++i;
        }

        else if (A[i] > B[j]) {
            vectorFinal.push_back(B[j]);
            ++j;
        }

        else {
            vectorFinal.push_back(A[i]);
            ++i; ++j;
        }

    }

    while (i < A.size()) {
        vectorFinal.push_back(A[i]);
        ++i;
    }

    while (j < B.size()) { 
        vectorFinal.push_back(B[j]);
        ++j;
    }

    return vectorFinal;
}

void resuelveCaso() {
    int elem_vectorA; cin >> elem_vectorA;
    int elem_vectorB; cin >> elem_vectorB;

    vector<int> vectorA(elem_vectorA);
    vector<int> vectorB(elem_vectorB);
    for (int i = 0; i < elem_vectorA; ++i) cin >> vectorA[i];
    for (int i = 0; i < elem_vectorB; ++i) cin >> vectorB[i];

    vector<int> vectorFinal = ordenarVectores(vectorA, vectorB);
    cout << vectorFinal[0];
    for (int i = 1; i < vectorFinal.size(); ++i) cout << ' ' << vectorFinal[i];
    cout << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}