SRC=tests_catch.cpp main_test.cpp Vecteur.cpp Chaine.cpp
EXE = cpp5
CXX = g++

CXXFLAGS = -Wall -Wextra -g -O2 -MMD
LDFLAGS =

OBJ=$(addprefix build/,$(SRC:.cpp=.o))

all : $(OBJ)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)

build/%.o : %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean :
	rm -rf build cpp5