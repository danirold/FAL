// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int resolver_no_final(int num1, int num2) {
    if (num1 < 10 && num2 < 10) return (num1 + num2) % 10;
    else if (num1 >= 10 && num2 < 10) return resolver_no_final(num1 / 10, 0) * 10 + (num1 % 10 + num2) % 10;
    else if (num1 < 10 && num2 >= 10) return resolver_no_final(0, num2 / 10) * 10 + (num1 + num2 % 10) % 10;
    else return resolver_no_final(num1 / 10, num2 / 10) * 10 + (num1 % 10 + num2 % 10) % 10;
}

/* DEFINICION RECURSIVA DE LA FUNCION
  resolver_no_final(n1, n2) {
                               (n1 + n2) % 10   si n1 < 10 && n2 < 10
                               resolver_no_final(n1 / 10, 0) * 10 + (n1 % 10 + n2) % 10   si n1 >= 10 && n2 < 10
                               resolver_no_final(0, n2 / 10) * 10 + (n1 + n2 % 10) % 10   si n1 < 10 && n2 >= 10
                               resolver_no_final(n1/10, n2/10) * 10 + (n1 % 10 + n2 % 10) % 10  si n1 >= 10 && n2 >= 10
                         }

*/

int resolver_final(int num1, int num2, int p, int j) {
    if (num1 < 10 && num2 < 10) return ((num1 + num2) % 10) * p + j;
    else if (num1 >= 10 && num2 < 10) return resolver_final(num1 / 10, 0, p * 10, ((num1 % 10 + num2) % 10) * p + j);
    else if (num1 < 10 && num2 >= 10) return resolver_final(0, num2 / 10, p * 10, ((num1 + num2 % 10) % 10) * p + j);
    else return resolver_final(num1 / 10, num2 / 10, p * 10, ((num1 % 10 + num2 % 10) % 10) * p + j);
}

/* DEFINICION RECURSIVA DE LA FUNCION
  resolver_final(n1, n2) {
                               ((n1 + n2) % 10) * p + j   si n1 < 10 && n2 < 10
                               resolver_no_final(n1 / 10, 0, p * 10, ((num1 % 10 + num2) % 10) * p + j)   si n1 >= 10 && n2 < 10
                               resolver_no_final(0, n2 / 10, p * 10, ((num1 + num2 % 10) % 10) * p + j)   si n1 < 10 && n2 >= 10 
                               resolver_final(num1 / 10, num2 / 10, p * 10, ((num1 % 10 + num2 % 10) % 10) * p + j)  si n1 >= 10 && n2 >= 10
                         }

*/

void resuelveCaso() {
    int num1, num2;
    cin >> num1 >> num2;
    cout << resolver_no_final(num1, num2) << ' ' << resolver_final(num1, num2, 1, 0) << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}