#include <iostream>
#include <string>
#include "posicion.h"

using namespace std;

int main () {

    // Probandando Getter y Setter de Posicion
    Posicion p(3, 4);
    cout << p.getX() << endl; // Imprime 3
    cout << p.getY() << endl; // Imprime 4

    p.set(10, 12);
    cout << p.getX() << endl; // Ahora imprime 10
    cout << p.getY() << endl; // Ahora imprime 12
    
    return 0;
}

