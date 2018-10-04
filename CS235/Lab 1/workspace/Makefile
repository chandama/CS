main: main.o Arena.o Fighter.o Archer.o Robot.o Cleric.o
	g++ -std=c++11 main.o Arena.o Fighter.o Archer.o Robot.o Cleric.o -o main

Arena.o: Arena.cpp Arena.h ArenaInterface.h Fighter.h Cleric.h Robot.h Archer.h
	g++ -std=c++11 -c Arena.cpp
	
Fighter.o: Fighter.cpp Fighter.h FighterInterface.h
	g++ -std=c++11 -c Fighter.cpp
	
Cleric.o: Cleric.cpp Cleric.h Fighter.h
	g++ -std=c++11 -c Cleric.cpp
	
Robot.o: Robot.cpp Robot.h Fighter.h
	g++ -std=c++11 -c Robot.cpp

Archer.o: Archer.cpp Archer.h Fighter.h
	g++ -std=c++11 -c Archer.cpp
	
main.o: main.cpp Arena.h
	g++ -std=c++11 -c main.cpp