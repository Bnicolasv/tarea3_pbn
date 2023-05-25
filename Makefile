CC=g++
flags=#-Wundef -Werror -Wall -Wextra -Wuninitialized -Winit-self
exec=tarea_3

$(exec): main.o mapa.o
	$(CC) $(flags) main.o juego.o mapa.o personaje.o posicion.o -o $(exec)

run: $(exec)
	./$(exec)
	
all: clean run 

main.o: main.cpp
	$(CC) $(flags) main.cpp -o main.o -c

juego.o: juego.cpp
	$(CC) $(flags) juego.cpp -o juego.o -c

mapa.o: mapa.cpp
	$(CC) $(flags) mapa.cpp -o mapa.o -c

personaje.o: juego.cpp
	$(CC) $(flags) personaje.cpp -o personaje.o -c

posicion.o: posicion.cpp
	$(CC) $(flags) posicion.cpp -o posicion.o -c

clean:
	rm *.o $(exec)