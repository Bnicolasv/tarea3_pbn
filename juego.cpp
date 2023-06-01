#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include "juego.h"

using namespace std;


void Juego::chequearGanador() {
    vector<vector<Personaje*>> casillas = mapa.getCasillas();

    int ancho = mapa.getAncho();
    int alto = mapa.getAlto();

    int soldados_ejercito1_vivos = 0;
    int soldados_ejercito2_vivos = 0;

    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            if (casillas[i][j] != nullptr && casillas[i][j]->getEjercito() == 1 && casillas[i][j]->getVida() > 0) {
                soldados_ejercito1_vivos++;
            }
            else if (casillas[i][j] != nullptr && casillas[i][j]->getEjercito() == 2 && casillas[i][j]->getVida() > 0) {
                soldados_ejercito2_vivos++;
            }
            else {
                continue;
            }
        }
    }

    if (soldados_ejercito1_vivos == 0 && soldados_ejercito2_vivos > 0) {
        cout << "Todos los soldados del ejercito 1 han muerto. Ha ganado el ejercito 2" << endl;
    }

    else if (soldados_ejercito2_vivos == 0 && soldados_ejercito1_vivos > 0) {
        cout << "Todos los soldados del ejercito 2 han muerto. Ha ganado el ejercito 1" << endl;
    }

    else {
        cout << "Existen soldados vivos de ambos ejercitos. La batalla continua" << endl;
    }
}

int Juego::calcularTurno() {
    vector<vector<Personaje*>> casillas = mapa.getCasillas();

    int ancho = mapa.getAncho();
    int alto = mapa.getAlto();

    float suma_velocidades_ejercito1 = 0;
    int aux = 0;
    float promedio_velocidad_ejercito1 = 0;

    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            if (casillas[i][j] != nullptr && casillas[i][j]->getEjercito() == 1) {
                aux++;
                suma_velocidades_ejercito1 += casillas[i][j]->getVelocidad();
            }
            else {
                continue;
            }
        }
    }

    promedio_velocidad_ejercito1 = suma_velocidades_ejercito1 / aux;   

    float suma_velocidades_ejercito2 = 0;
    int aux2 = 0;
    float promedio_velocidad_ejercito2 = 0;

    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            if (casillas[i][j] != nullptr && casillas[i][j]->getEjercito() == 2) {
                aux2++;
                suma_velocidades_ejercito2 += casillas[i][j]->getVelocidad();
            }
            else {
                continue;
            }
        }
    }

    promedio_velocidad_ejercito2 = suma_velocidades_ejercito2 / aux2;   
    

    int indice_ejercito = 0;
    if (promedio_velocidad_ejercito1 > promedio_velocidad_ejercito2) {
        std::cout << "Comienzan atacando los soldados del ejercito 1" << std::endl;        
        indice_ejercito = 1;
    }
    else {
        std::cout << "Comienzan atacando los soldados del ejercito 2" << std::endl;
        indice_ejercito = 2;
    }
    return indice_ejercito;
}

void Juego::mostrarMapa() {
    mapa.mostrarCasillas();
}

void Juego::combate(Personaje *p1, Personaje *p2) {
    // Ataca primero el personaje con mayor velocidad. Si tienen la misma velocidad, parte el que tenga 
    // mayor ataque. Si tienen misma velocidad y ataque, parte el que tenga mayor vida. 
    
    std::cout << "Comienza la pelea entre " << p1->getNombre() << p1->getEjercito() <<" y " << p2->getNombre() << p2->getEjercito() <<":" << std::endl; 

    Personaje* atacante;
    Personaje* defensor;
    Personaje* ganador;

    if (p1->getVelocidad() > p2->getVelocidad()) {
        atacante = p1;
        defensor = p2;

        std::cout << "La velocidad de " << atacante->getNombre() << atacante->getEjercito() << " es de " << atacante->getVelocidad() << ", ";
        std::cout << "la de " << defensor->getNombre() << defensor->getEjercito() << " es de " << defensor->getVelocidad() << ", ";
        std::cout << "comienza atacando " << atacante->getNombre() << atacante->getEjercito() << std::endl;
    }

    else if (p2->getVelocidad() > p1->getVelocidad()) {
        atacante = p2;
        defensor = p1;

        std::cout << "La velocidad de " << atacante->getNombre() << atacante->getEjercito() << " es de " << atacante->getVelocidad() << ", ";
        std::cout << "la de " << defensor->getNombre() << defensor->getEjercito() << " es de " << defensor->getVelocidad() << ", ";
        std::cout << "comienza atacando " << atacante->getNombre() << atacante->getEjercito() << std::endl;
    }

    else if (p1->ataque() > p2->ataque()) {
        atacante = p1;
        defensor = p2;
        
        std::cout << "El ataque de " << atacante->getNombre() << atacante->getEjercito() << " es de " << atacante->ataque() << ", ";
        std::cout << "el de " << defensor->getNombre() << defensor->getEjercito() << " es de " << defensor->ataque() << ", ";
        std::cout << "comienza atacando " << atacante->getNombre() << atacante->getEjercito() << std::endl;
    }

    else if (p2->ataque() > p1->ataque()) {
        atacante = p2;
        defensor = p1;

        std::cout << "El ataque de " << atacante->getNombre() << atacante->getEjercito() << " es de " << atacante->ataque() << ", ";
        std::cout << "el de " << defensor->getNombre() << defensor->getEjercito() << " es de " << defensor->ataque() << ", ";
        std::cout << "comienza atacando " << atacante->getNombre() << atacante->getEjercito() << std::endl;
    }

    else if (p1->getVida() > p2->getVida()) {
        atacante = p1;
        defensor = p2;

        std::cout << "La vida de " << atacante->getNombre() << atacante->getEjercito() << " es de " << atacante->getVida() << ",";
        std::cout << "la de " << defensor->getNombre() << defensor->getEjercito() << " es de " << defensor->getVida() << ",";
        std::cout << "comienza atacando" << atacante->getNombre() << atacante->getEjercito() << std::endl;
    }

    else if (p2->getVida() > p1->getVida()) {
        atacante = p2;
        defensor = p1;

        std::cout << "La vida de " << atacante->getNombre() << atacante->getEjercito() << " es de " << atacante->getVida() << ",";
        std::cout << "la de " << defensor->getNombre() << defensor->getEjercito() << " es de " << defensor->getVida() << ",";
        std::cout << "comienza atacando" << atacante->getNombre() << atacante->getEjercito() << std::endl;
    }

    // Una vez que ya se sabe quien ataca y quien defiende, comienzan a pegarse hasta que uno de ellos pierda
    while (atacante->getVida() > 0 && defensor->getVida() > 0) {
        defensor->recibirAtaque(atacante);
        std::cout << atacante->getNombre() << " inflinge " << atacante->ataque() << " de dano a ";
        std::cout << defensor->getNombre() << ", vida restante: " << defensor->getVida() << std::endl;

        // https://www.geeksforgeeks.org/swap-in-cpp/
        std::swap(atacante, defensor);
    }

    // Evalua con el operador ternario '?' cual personaje quedo como ganador
    // https://es.stackoverflow.com/questions/384162/qu%C3%A9-hace-el-operador-en-c
    ganador = (p1->getVida() > 0) ? p1:p2;
    std::cout << "Combate finalizado, ha ganado " << ganador->getNombre() << ganador->getEjercito() << std::endl;
}


void Juego::jugar() {
    ifstream archivo("soldados_short.txt");
    string linea;
    getline(archivo, linea);

    stringstream dimensiones(linea);
    string ancho_str, alto_str;
    getline(dimensiones, ancho_str, ',');
    getline(dimensiones, alto_str, ',');
    int ancho = stoi(ancho_str);
    int alto = stoi(alto_str);

    getline(archivo, linea);
    stringstream soldados1(linea);
    int cantidad_de_soldados1;
    soldados1 >> cantidad_de_soldados1;

    Personaje *soldados_ejercito1[cantidad_de_soldados1];

    for (int i = 0; i < cantidad_de_soldados1; i++) {
        getline(archivo, linea);
        stringstream soldado1(linea);
        string nombre;
        int vida, fuerza, velocidad, pos_x, pos_y;

        getline(soldado1, nombre, ',');
        soldado1 >> vida;
        soldado1.ignore();
        soldado1 >> fuerza;
        soldado1.ignore();
        soldado1 >> velocidad;
        soldado1.ignore();
        soldado1 >> pos_x;
        soldado1.ignore();
        soldado1 >> pos_y;

        Posicion pos = Posicion(pos_x, pos_y);
        soldados_ejercito1[i] = new Personaje(nombre, vida, fuerza, velocidad, pos, 1);
    }

    getline(archivo, linea);
    stringstream soldados2(linea);
    int cantidad_de_soldados2;
    soldados2 >> cantidad_de_soldados2;

    Personaje *soldados_ejercito2[cantidad_de_soldados2];

    for (int i = 0; i < cantidad_de_soldados2; i++) {
        getline(archivo, linea);
        stringstream soldado2(linea);
        string nombre;
        int vida, fuerza, velocidad, pos_x, pos_y;

        getline(soldado2, nombre, ',');
        soldado2 >> vida;
        soldado2.ignore(); 
        soldado2 >> fuerza;
        soldado2.ignore();
        soldado2 >> velocidad;
        soldado2.ignore();
        soldado2 >> pos_x;
        soldado2.ignore();
        soldado2 >> pos_y;

        Posicion pos = Posicion(pos_x, pos_y);
        soldados_ejercito2[i] = new Personaje(nombre, vida, fuerza, velocidad, pos, 2);
    }
    archivo.close();

    mapa = Mapa(alto, ancho);
    // Mapa* mapa_ptr = &mapa;
    
    cout << "Tablero vacio" << endl;
    mostrarMapa();

    for (int i = 0; i < cantidad_de_soldados1; i++) {
        mapa.agregarPersonaje(soldados_ejercito1[i]);
    }

    for (int j = 0; j < cantidad_de_soldados2; j++) {
        mapa.agregarPersonaje(soldados_ejercito2[j]);
    }

    cout << "Turno 0" << endl;
    mostrarMapa();


    // mapa_ptr->mostrarCasillas();
    int equipo_inicial = calcularTurno();

    vector<vector<Personaje*>> casillas = mapa.getCasillas();

    if (equipo_inicial == 1){
        bool continuar = true;
        while (continuar){
            for (int i = 0; i < alto; i++){
                for (int j = 0; j < ancho; j++){

                        soldados_ejercito1[j]->moverse(mapa, *this);
                        soldados_ejercito2[i]->moverse(mapa, *this);

                    } 
                }
            continuar = false;
        }
    }
    
    mostrarMapa();                       


    // cout << "TEST COMBATES" << endl;
    // for (int i = 0; i < cantidad_de_soldados1; i++) {
    //     combate(soldados_ejercito1[i], soldados_ejercito2[i]);
    // }
    // cout << "----------------------------------------" << endl;

    // ESTO HAY QUE SACARLO PORQUE PARA CADA COMBATE SE LLAMARA A THIS
    // SOLO SE DEBE HACER DELETE CON UN FOR DE LOS QUE QUEDEN VIVOS UNA VEZ UN EJERCITO GANE
    for (int i = 0; i < cantidad_de_soldados1; i++) {
        delete soldados_ejercito1[i];
    }

    for (int i = 0; i < cantidad_de_soldados2; i++) {
        delete soldados_ejercito2[i];
    }
}

