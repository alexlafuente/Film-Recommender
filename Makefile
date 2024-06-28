CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11


program: program.o Plataforma.o Usuari.o Film.o
	$(LINK.cc) -o $@ $^
	
program.o: program.cpp Plataforma.hpp Usuari.hpp Film.hpp

Plataforma.o: Plataforma.cpp Plataforma.hpp Usuari.hpp Film.hpp

Usuari.o: Usuari.cpp Usuari.hpp Film.hpp

Film.o: Film.cpp Film.hpp


.PHONY: clean
clean:
	rm -vf program.o Plataforma.o Usuari.o Film.o program
