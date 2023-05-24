#include <iostream>
#include <string>
#include <cstring>
// #include "posicion.h"

using namespace std;

int main () {

    // Probandando Getter y Setter de Posicion
    // Posicion p(3, 4);
    // cout << p.getX() << endl; // Imprime 3
    // cout << p.getY() << endl; // Imprime 4

    // p.set(10, 12);
    // cout << p.getX() << endl; // Ahora imprime 10
    // cout << p.getY() << endl; // Ahora imprime 12


    // CREAR TABLERO
    int ANCHO = 10;
    int ALTO = 10;

    char arr[3][3][7] = {{"Jose", "Pedro", "Juan"}, {"Matias", "Jose", "Juan"}, {"Pedro", "Pablo", "Benja"}};
    char arr2[3][3][2] = {{"1", "2", "1"}, {"1", "1", "1"}, {"2", "2", "1"}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (strlen(arr[i][j]) == 5) {
                cout << "|" << arr[i][j];
            } else {
                cout << "|" << arr[i][j];
                for (int k = 0; k < 9 - strlen(arr[i][j]); k++) {
                    cout << " ";
                }
            }
        }
        cout << "|" << endl;
        cout << "|          |          |" << endl;
    }

    return 0;
}

