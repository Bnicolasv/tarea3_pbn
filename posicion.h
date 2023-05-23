#include <iostream>

class Posicion{
    private:
        int x, y;
        
    public:
        int getX();
        int getY();
        void set(int x, int y);
        Posicion(int x, int y);
        ~Posicion();
};