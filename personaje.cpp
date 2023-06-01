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

Personaje::~Personaje() {
    // std::cout << "El personaje ha sido eliminado del tablero" << std::endl;
}

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

Posicion Personaje::moverse(Mapa mapa, Juego juego) { 
    int pos_ancho = pos->getX();
    int pos_alto = pos->getY();
    
    int casilla_central_ancho = mapa.casillaCentralX(); 
    int casilla_central_alto = mapa.casillaCentralY();
    int ejercito = this->ejercito;

    std::vector<std::vector<Personaje*> > casillas = mapa.getCasillas();

    if (pos_ancho == casilla_central_ancho && pos_alto == casilla_central_alto) {
        return *pos;
    }

    // Primer cuadrante (arriba a la derecha del centro) -> ((pos_ancho - casilla_central_ancho > 0) && (pos_alto - casilla_central_alto < 0))
    else if ((pos_ancho - casilla_central_ancho > 0) && (pos_alto - casilla_central_alto < 0)) {
        std::cout << this->getNombre() << this->getEjercito() << " Trata de moverse abajo a la izquierda" << std::endl;
        if ((pos_ancho - 1 != casilla_central_ancho) && (pos_alto + 1 != casilla_central_alto)) {
            if (casillas[pos_ancho - 1][pos_alto + 1] == nullptr) {
                pos -> set(pos_ancho - 1, pos_alto + 1);
                std::cout << this->getNombre() << this->getEjercito() <<" Se mueve abajo a la izquierda" << std::endl;
                return* pos;
            }

            else if (casillas[pos_ancho - 1][pos_alto + 1] != nullptr) {
                if (casillas[pos_ancho - 1][pos_alto + 1]->getEjercito() != ejercito) {
                    juego.combate(casillas[pos_ancho - 1][pos_alto + 1], this); // El combate actualizara this -> vida
                    if (vida > 0) {
                        pos -> set(pos_ancho - 1, pos_alto + 1);
                        std::cout << this->getNombre() << this->getEjercito() <<" Se mueve abajo a la izquierda" << std::endl;
                        return* pos;
                    }
                    else {
                        std::cout << this->getNombre() << this->getEjercito() << " Se muere" << std::endl;
                        mapa.eliminarPersonaje(this);
                    }
                }
                else if (casillas[pos_ancho - 1][pos_alto + 1]->getEjercito() == ejercito) {
                    if (pos_alto != casilla_central_alto) {
                        if (casillas[pos_ancho][pos_alto + 1] == nullptr) {
                            pos -> set(pos_ancho, pos_alto + 1);
                            std::cout << this->getNombre() << this->getEjercito() <<" Se mueve abajo" << std::endl;
                            return* pos;
                        }
                        else if (casillas[pos_ancho][pos_alto + 1] != nullptr) {
                            if (casillas[pos_ancho][pos_alto + 1]->getEjercito() != ejercito) {
                                juego.combate(casillas[pos_ancho][pos_alto + 1], this); // El combate actualizara this -> vida
                                if (vida > 0) {
                                    pos -> set(pos_ancho, pos_alto + 1);
                                    std::cout << this->getNombre() << this->getEjercito() <<" Se mueve abajo" << std::endl;
                                    return* pos;
                                }
                                else {
                                    std::cout << this->getNombre() << this->getEjercito() << " Se muere" << std::endl;
                                    mapa.eliminarPersonaje(this);
                                }
                            }
                            else if (casillas[pos_ancho][pos_alto + 1]->getEjercito() == ejercito) {
                                std::cout << this->getNombre() << this->getEjercito() << " Se queda donde mismo" << std::endl;
                                return *pos;
                            }
                        }
                    }
                    else {
                        return *pos;
                    }
                }
            }
        }
    }
    
    // Segundo cuadrante (arriba a la izquierda del centro) -> ((pos_ancho - casilla_central_ancho < 0) && (pos_alto - casilla_central_alto < 0))
    else if ((pos_ancho - casilla_central_ancho < 0) && (pos_alto - casilla_central_alto < 0)) {
        std::cout << this->getNombre() << this->getEjercito() << " Trata de moverse abajo a la derecha" << std::endl;
        if ((pos_ancho + 1 != casilla_central_ancho) && (pos_alto + 1 != casilla_central_alto)) {
            if (casillas[pos_ancho + 1][pos_alto + 1] == nullptr) {
            pos -> set(pos_ancho + 1, pos_alto + 1);
            std::cout << this->getNombre() << this->getEjercito() <<" Se mueve abajo a la derecha" << std::endl;
            return* pos;
            }

            else if (casillas[pos_ancho + 1][pos_alto + 1] != nullptr) {
                if (casillas[pos_ancho + 1][pos_alto + 1]->getEjercito() != ejercito) {
                    juego.combate(casillas[pos_ancho + 1][pos_alto + 1], this); // El combate actualizara this -> vida
                    if (vida > 0) {
                        pos -> set(pos_ancho + 1, pos_alto + 1);
                        std::cout << this->getNombre() << this->getEjercito() <<" Se mueve abajo a la derecha" << std::endl;
                        return* pos;
                    }
                    else {
                        std::cout << this->getNombre() << this->getEjercito() <<" Se muere" << std::endl;
                        mapa.eliminarPersonaje(this);
                    }
                }
                else if (casillas[pos_ancho + 1][pos_alto + 1]->getEjercito() == ejercito) {
                    if (pos_alto != casilla_central_alto) {
                        if (casillas[pos_ancho][pos_alto + 1] == nullptr) {
                            pos -> set(pos_ancho, pos_alto + 1);
                            std::cout << this->getNombre() << this->getEjercito() <<" Se mueve abajo" << std::endl;
                            return* pos;
                        }
                        else if (casillas[pos_ancho][pos_alto + 1] != nullptr) {
                            if (casillas[pos_ancho][pos_alto + 1]->getEjercito() != ejercito) {
                                juego.combate(casillas[pos_ancho][pos_alto + 1], this); // El combate actualizara this -> vida
                                if (vida > 0) {
                                    pos -> set(pos_ancho, pos_alto + 1);
                                    std::cout << this->getNombre() << this->getEjercito() <<" Se mueve abajo" << std::endl;
                                    return* pos;
                                }
                                else {
                                    std::cout << this->getNombre() << this->getEjercito() <<" Se muere" << std::endl;
                                    mapa.eliminarPersonaje(this);
                                }
                            }
                            else if (casillas[pos_ancho][pos_alto + 1]->getEjercito() == ejercito) {
                                std::cout << this->getNombre() << this->getEjercito() <<" Se queda donde mismo" << std::endl;
                                return *pos;
                            }
                        }
                    }
                    else {
                        return *pos;
                    }
                    }
                }
            }
        }

    // Tercer cuadrante (izquierda abajo del centro) -> ((pos_ancho - casilla_central_ancho < 0) && (pos_alto - casilla_central_alto > 0))
    else if ((pos_ancho - casilla_central_ancho < 0) && (pos_alto - casilla_central_alto > 0)) {
        std::cout << this->getNombre() << this->getEjercito() << " Trata de moverse arriba a la derecha" << std::endl;
        if ((pos_ancho + 1 != casilla_central_ancho) && (pos_alto - 1 != casilla_central_alto)) {
            if (casillas[pos_ancho + 1][pos_alto - 1] == nullptr) {
                pos -> set(pos_ancho + 1, pos_alto - 1);
                std::cout << this->getNombre() << this->getEjercito() <<" Se mueve arriba a la derecha" << std::endl;
                return* pos;
            }

            else if (casillas[pos_ancho + 1][pos_alto - 1] != nullptr) {
                if (casillas[pos_ancho + 1][pos_alto - 1]->getEjercito() != ejercito) {
                    juego.combate(casillas[pos_ancho + 1][pos_alto - 1], this); // El combate actualizara this -> vida
                    if (vida > 0) {
                        pos -> set(pos_ancho + 1, pos_alto - 1);
                        std::cout << this->getNombre() << this->getEjercito() <<" Se mueve arriba a la derecha" << std::endl;
                        return* pos;
                    }
                    else {
                        std::cout << this->getNombre() << this->getEjercito() <<" Se muere" << std::endl;
                        mapa.eliminarPersonaje(this);
                    }
                }
                else if (casillas[pos_ancho + 1][pos_alto - 1]->getEjercito() == ejercito) {
                    if (pos_alto != casilla_central_alto) {
                        if (casillas[pos_ancho][pos_alto - 1] == nullptr) {
                            pos -> set(pos_ancho, pos_alto - 1);
                            std::cout << this->getNombre() << this->getEjercito() <<" Se mueve arriba" << std::endl;
                            return* pos;
                        }
                        else if (casillas[pos_ancho][pos_alto - 1] != nullptr) {
                            if (casillas[pos_ancho][pos_alto - 1]->getEjercito() != ejercito) {
                                juego.combate(casillas[pos_ancho][pos_alto + 1], this); // El combate actualizara this -> vida
                                if (vida > 0) {
                                    pos -> set(pos_ancho, pos_alto - 1);
                                    std::cout << this->getNombre() << this->getEjercito() <<" Se mueve arriba" << std::endl;
                                    return* pos;
                                }
                                else {
                                    std::cout << this->getNombre() << this->getEjercito() <<" Se muere" << std::endl;
                                    mapa.eliminarPersonaje(this);
                                }
                            }
                            else if (casillas[pos_ancho][pos_alto - 1]->getEjercito() == ejercito) {
                                std::cout << this->getNombre() << this->getEjercito() <<" Se queda donde mismo" << std::endl;
                                return *pos;
                            }
                        }
                    }
                    else {
                        std::cout << this->getNombre() << this->getEjercito() <<" Se queda donde mismo" << std::endl;
                        return *pos;
                    }
                    }
                }
            }
        }
        
    // Cuarto cuadrante (abajo a la derecha del centro) -> ((pos_ancho - casilla_central_ancho > 0) && (pos_alto - casilla_central_alto > 0))
    else if ((pos_ancho - casilla_central_ancho > 0) && (pos_alto - casilla_central_alto > 0)) {
        std::cout << this->getNombre() << this->getEjercito() << " Trata de moverse arriba a la izquierda" << std::endl;
        if ((pos_ancho - 1 != casilla_central_ancho) && (pos_alto - 1 != casilla_central_alto)) {
            if (casillas[pos_ancho - 1][pos_alto - 1] == nullptr) {
                pos -> set(pos_ancho - 1, pos_alto - 1);
                std::cout << this->getNombre() << this->getEjercito() <<" Se mueve arriba a la izquierda" << std::endl;
                return* pos;
            }

            else if (casillas[pos_ancho - 1][pos_alto - 1] != nullptr) {
                if (casillas[pos_ancho - 1][pos_alto - 1]->getEjercito() != ejercito) {
                    juego.combate(casillas[pos_ancho - 1][pos_alto - 1], this); // El combate actualizara this -> vida
                    if (vida > 0) {
                        pos -> set(pos_ancho - 1, pos_alto - 1);
                        std::cout << this->getNombre() << this->getEjercito() <<" Se mueve arriba a la izquierda" << std::endl;
                        return* pos;
                    }
                    else {
                        std::cout << this->getNombre() << this->getEjercito() <<" Se muere" << std::endl;
                        mapa.eliminarPersonaje(this);
                    }
                }
                else if (casillas[pos_ancho - 1][pos_alto - 1]->getEjercito() == ejercito) {
                    if (pos_alto != casilla_central_alto) {
                        if (casillas[pos_ancho][pos_alto - 1] == nullptr) {
                            pos -> set(pos_ancho, pos_alto - 1);
                            std::cout << this->getNombre() << this->getEjercito() <<" Se mueve arriba" << std::endl;
                            return* pos;
                        }
                        else if (casillas[pos_ancho][pos_alto - 1] != nullptr) {
                            if (casillas[pos_ancho][pos_alto - 1]->getEjercito() != ejercito) {
                                juego.combate(casillas[pos_ancho][pos_alto - 1], this); // El combate actualizara this -> vida
                                if (vida > 0) {
                                    pos -> set(pos_ancho, pos_alto - 1);
                                    std::cout << this->getNombre() << this->getEjercito() <<" Se mueve arriba" << std::endl;
                                    return* pos;
                                }
                                else {
                                    std::cout << this->getNombre() << this->getEjercito() <<" Se muere" << std::endl;
                                    mapa.eliminarPersonaje(this);
                                }
                            }
                            else if (casillas[pos_ancho][pos_alto - 1]->getEjercito() == ejercito) {
                                std::cout << this->getNombre() << this->getEjercito() <<" Se queda donde mismo" << std::endl;
                                return *pos;
                            }
                        }
                    }
                    else {
                        return *pos;
                    }
                    }
                }
            }
        }
        
    // Pseudo quinto cuadrante (pos_ancho == casilla_central_ancho && pos_alto < casilla_central_alto)
    else if (pos_ancho == casilla_central_ancho && pos_alto < casilla_central_alto) {
        std::cout << this->getNombre() << this->getEjercito() << " Trata de moverse abajo" << std::endl;
        if (pos_alto - 1 != casilla_central_alto) {
            if (casillas[pos_ancho][pos_alto + 1] == nullptr) {
                pos -> set(pos_ancho, pos_alto + 1);
                std::cout << this->getNombre() << this->getEjercito() <<" Se mueve abajo" << std::endl;
                return* pos;
            }
            else if (casillas[pos_ancho][pos_alto + 1] != nullptr) {
                if (casillas[pos_ancho][pos_alto + 1]->getEjercito() != ejercito) {
                    juego.combate(casillas[pos_ancho][pos_alto + 1], this); 
                    if (vida > 0) {
                        pos -> set(pos_ancho, pos_alto + 1);
                        std::cout << this->getNombre() << this->getEjercito() <<" Se mueve abajo" << std::endl;
                        return* pos;
                    }
                    else {
                        std::cout << this->getNombre() << this->getEjercito() <<" Se muere" << std::endl;
                        mapa.eliminarPersonaje(this);
                    }
                }
                else if (casillas[pos_ancho][pos_alto + 1]->getEjercito() == ejercito) {
                    std::cout << this->getNombre() << this->getEjercito() <<" Se queda donde mismo" << std::endl;
                    return *pos;
                }
                }
            }
        }
    
    // Pseudo sexto cuadrante (pos_ancho < casilla_central_ancho && pos_alto == casilla_central_alto)
    else if (pos_ancho < casilla_central_ancho && pos_alto == casilla_central_alto) {
        std::cout << this->getNombre() << this->getEjercito() << " Trata de moverse derecha" << std::endl;
        if (pos_ancho + 1 != casilla_central_ancho) {
            if (casillas[pos_ancho + 1][pos_alto] == nullptr) {
                pos -> set(pos_ancho + 1, pos_alto);
                std::cout << this->getNombre() << this->getEjercito() <<" Se mueve derecha" << std::endl;
                return* pos;
            }
            else if (casillas[pos_ancho + 1][pos_alto] != nullptr) {
                if (casillas[pos_ancho + 1][pos_alto]->getEjercito() != ejercito) {
                    juego.combate(casillas[pos_ancho + 1][pos_alto], this); 
                    if (vida > 0) {
                        pos -> set(pos_ancho + 1, pos_alto);
                        std::cout << this->getNombre() << this->getEjercito() <<" Se mueve derecha" << std::endl;
                        return* pos;
                    }
                    else {
                        std::cout << this->getNombre() << this->getEjercito() <<" Se muere" << std::endl;
                        mapa.eliminarPersonaje(this);
                    }
                }
                else if (casillas[pos_ancho + 1][pos_alto]->getEjercito() == ejercito) {
                    std::cout << this->getNombre() << this->getEjercito() <<" Se queda donde mismo" << std::endl;
                    return *pos;
                }
                }
            }
        }

    // Pseudo septimo cuadrante (pos_ancho == casilla_central_ancho && pos_alto > casilla_central_alto)
    else if (pos_ancho == casilla_central_ancho && pos_alto > casilla_central_alto) {
        std::cout << this->getNombre() << this->getEjercito() << " Trata de moverse arriba" << std::endl;
        if (pos_alto - 1 != casilla_central_alto) {
            if (casillas[pos_ancho][pos_alto - 1] == nullptr) {
                pos -> set(pos_ancho, pos_alto - 1);
                std::cout << this->getNombre() << this->getEjercito() <<" Se mueve arriba" << std::endl;
                return* pos;
            }
            else if (casillas[pos_ancho][pos_alto - 1] != nullptr) {
                if (casillas[pos_ancho][pos_alto - 1]->getEjercito() != ejercito) {
                    juego.combate(casillas[pos_ancho][pos_alto - 1], this); 
                    if (vida > 0) {
                        pos -> set(pos_ancho, pos_alto - 1);
                        std::cout << this->getNombre() << this->getEjercito() <<" Se mueve arriba" << std::endl;
                        return* pos;
                    }
                    else {
                        std::cout << this->getNombre() << this->getEjercito() <<" Se muere" << std::endl;
                        mapa.eliminarPersonaje(this);
                    }
                }
                else if (casillas[pos_ancho][pos_alto - 1]->getEjercito() == ejercito) {
                    std::cout << this->getNombre() << this->getEjercito() <<" Se queda donde mismo" << std::endl;
                    return *pos;
                }
                }
            }
        }
    
    // Pseudo octavo cuadrante (pos_ancho > casilla_central_ancho && pos_alto == casilla_central_alto)
    else if (pos_ancho > casilla_central_ancho && pos_alto == casilla_central_alto) {
        std::cout << this->getNombre() << this->getEjercito() << " Trata de moverse izquierda" << std::endl;
        if (pos_ancho + 1 != casilla_central_ancho) {
            if (casillas[pos_ancho - 1][pos_alto] == nullptr) {
                pos -> set(pos_ancho - 1, pos_alto);
                std::cout << this->getNombre() << this->getEjercito() <<" Se mueve izquierda" << std::endl;
                return* pos;
            }
            else if (casillas[pos_ancho -1][pos_alto] != nullptr) {
                if (casillas[pos_ancho -1][pos_alto]->getEjercito() != ejercito) {
                    juego.combate(casillas[pos_ancho - 1][pos_alto], this); 
                    if (vida > 0) {
                        pos -> set(pos_ancho -1, pos_alto);
                        std::cout << this->getNombre() << this->getEjercito() <<" Se mueve izquierda" << std::endl;
                        return* pos;
                    }
                    else {
                        std::cout << this->getNombre() << this->getEjercito() <<" Se muere" << std::endl;
                        mapa.eliminarPersonaje(this);
                    }
                    }
                else if (casillas[pos_ancho -1][pos_alto]->getEjercito() == ejercito) {
                    std::cout << this->getNombre() << this->getEjercito() <<" Se queda donde mismo" << std::endl;
                    return *pos;
                }
                }
            }
        } 

    return *pos;   
}