CXX=g++
CXXFLAGS=-std=c++11
DEPS=Battle.h GymLeader.h Person.h Player.h Pokedesk.h Pokemon.h Stats.h Trainer.h utils.h tests.h

all: main

main: main.o Battle.o GymLeader.o Person.o Player.o Pokedesk.o Pokemon.o Stats.o Trainer.o utils.o 
	$(CXX) $(CXXFLAGS) -o main *.o

tests: tests.o Battle.o GymLeader.o Person.o Player.o Pokedesk.o Pokemon.o Stats.o Trainer.o utils.o 
	$(CXX) $(CXXFLAGS) -o tests *.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o
	rm -f main
	rm -f tests