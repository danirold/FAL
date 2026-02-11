// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

long int resolver_no_final(long int numero) {
    if (numero < 10 && numero % 2 == 0) return 0;
    else if (numero < 10 && numero % 2 == 1) return numero;
    else if (numero >= 10 && numero % 2 == 0) return resolver_no_final(numero / 10);
    else if (numero >= 10 && numero % 2 == 1) return resolver_no_final(numero / 10) * 10 + (numero % 10);
}

/* DEFINICION RECURSIVA DE LA FUNCION
  resolver_no_final(n) {
                               0   si n < 10 && (n % 2) = 0
                               n   si n < 10 && (n % 2) = 1
                               resolver_no_final(n/10)  si n>= 10 && (n % 2) = 0
                               resolver_no_final(n/10) * 10 + (n % 10)  si n >= 10 && (n % 2) = 1
                         }

*/

long int resolver_final(long int numero, long int p, long int j) {
    if (numero < 10 && numero % 2 == 0) return 0 * p + j;
    else if (numero < 10 && numero % 2 == 1) return numero * p + j;
    else if (numero >= 10 && numero % 2 == 0) return resolver_final(numero / 10, p, j);
    else if (numero >= 10 && numero % 2 == 1) return resolver_final(numero / 10, p * 10, (numero % 10) * p + j);
}

/* DEFINICION RECURSIVA DE LA FUNCION
  resolver_final(n, p, j) {
                               0 * p + j   si n < 10 && (n % 2) = 0
                               n * p + j   si n < 10 && (n % 2) = 1
                               resolver_final(n/10, p, j)  si n>= 10 && (n % 2) = 0
                               resolver_final(n/10, p * 10, (n % 10) * p + j)  si n >= 10 && (n % 2) = 1
                         }

*/

bool resuelveCaso() {
    long int num; cin >> num;

    if (!std::cin)
        return false;

    cout << resolver_no_final(num) << ' ' << resolver_final(num, 1, 0) << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}