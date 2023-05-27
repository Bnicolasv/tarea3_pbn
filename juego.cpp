#include <iostream>
#include <string>
#include "juego.h"
#include "personaje.h"
#include "posicion.h"
#include "mapa.h"


// void Juego::chequearGanador(){

// }

// int Juego::calcularTurno(){

// }

// void Juego::mostrarMapa(){

// }

void Juego::combate(Personaje *p1, Personaje *p2) {
    // Ataca primero el personaje con mayor velocidad. Si tienen la misma velocidad, parte el que tenga 
    // mayor ataque. Si tienen misma velocidad y ataque, parte el que tenga mayor vida. 
    
    std::cout << "Comienza la pelea entre " << p1->getNombre() << " y " << p2->getNombre() << ":" << std::endl; 

    Personaje* atacante;
    Personaje* defensor;
    Personaje* ganador;

    if (p1->getVelocidad() > p2->getVelocidad()) {
        atacante = p1;
        defensor = p2;

        // FALTA MOSTRAR JUNTO AL NOMBRE EL EJERCITO AL CUAL PERTENECEN 'BENJA1', 'PEDRO2'
        std::cout << "La velocidad de " << atacante->getNombre() << " es de " << atacante->getVelocidad() << ",";
        std::cout << "La de " << defensor->getNombre() << " es de " << defensor->getVelocidad() << ",";
        std::cout << "comienza atacando" << atacante->getNombre() << std::endl;
    }

    else if (p2->getVelocidad() > p1->getVelocidad()) {
        atacante = p2;
        defensor = p1;
    }

    else if (p1->ataque() > p2->ataque()) {
        atacante = p1;
        defensor = p2;
    }

    else if (p2->ataque() > p1->ataque()) {
        atacante = p2;
        defensor = p1;
    }

    else if (p1->getVida() > p2->getVida()) {
        atacante = p1;
        defensor = p2;
    }

    else if (p2->getVida() > p1->getVida()) {
        atacante = p2;
        defensor = p1;
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
    std::cout << "Combate finalizado, ha ganado " << ganador->getNombre() << std::endl;
}