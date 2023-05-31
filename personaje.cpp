#include <iostream>
#include <string>
#include "personaje.h"
#include "mapa.h"


Personaje::Personaje(std::string nombre, int vida, int fuerza, int velocidad, Posicion pos, int ejercito) {
    this -> nombre = nombre;
    this -> vida = vida;
    this -> fuerza = fuerza;
    this -> velocidad = velocidad;
    this -> pos = new Posicion(pos.getX(), pos.getY());
    this -> ejercito = ejercito;
}

Personaje::Personaje() {}

Personaje::~Personaje() {}

std::string Personaje::getNombre() const{
    return nombre;
}
int Personaje::getVida() const{
    return vida;
}

int Personaje::ataque() const{
    return fuerza;
}

int Personaje::getVelocidad() const{
    return velocidad;
}

Posicion Personaje::getPosicion() const{
    return *pos;
}

int Personaje::getEjercito() const {
    return ejercito;
}

void Personaje::recibirAtaque(Personaje* enemigo) {
    vida -= enemigo -> ataque();
}

// Posicion Personaje::moverse(Mapa mapa) {
//     Posicion posicionInicial = *pos;

//     int posicionInicialX = pos->getX();
//     int posicionInicialY = pos->getY();
    
//     int ancho = mapa.getAncho();
//     int alto = mapa.getAlto();
    
//     std::vector<std::vector<Personaje*> > casillas = mapa.getCasillas();

    // Primer cuadrante (arriba a la derecha del centro)











 
// }   
    


//Ejercito 1
// Si es que se encuentra entre las coordenadas X = 0 y casillaCentralX debe moverse a la derecha y si es que se encuentra entre las coordenadas Y = 0 y casillaCentralY debe moverse hacia abajo
// Si es que se encuentra entre casillaCentralX y X = ancho debe moverse a la izquierda y si es que se encuentra entre las coordenadas Y = 0 y casillaCentralY debe moverse hacia abajo



//Ejercito 2
// Si es que se encuentra entre las coordenadas X = 0 y casillaCentralX debe moverse a la derecha y si es que se encuentra entre las coordenadas Y = 0 y casillaCentralY debe moverse hacia arriba
// Si es que se encuentra entre casillaCentralX y X = ancho debe moverse a la izquierda y si es que se encuentra entre las coordenadas Y = 0 y casillaCentralY debe moverse hacia arriba

    // cada vez que se mueva debe usarse personaje->getPosicion().set(NUEVA POSICION HACIA DONDE SE MOVIO)