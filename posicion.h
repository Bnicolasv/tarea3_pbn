#include <iostream>

class Posicion{
    public:
        Posicion(int x, int y);
        ~Posicion();
    private:
        int x, y;
    public:
        int getX();
        int getY();
        void set(int x, int y);
};