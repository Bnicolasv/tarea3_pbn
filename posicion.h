#include "juego.h"

#ifndef POSICION_H
#define POSICION_H

class Posicion {
    public:
        Posicion(int x, int y);
        ~Posicion();

        int getX() const;
        int getY() const;
        void set(int x, int y);

    private:
        int x, y;
};

#endif