OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o evaluate.o utils.o
	g++ -o program.exe program.o evaluate.o utils.o

program.o: program.cpp evaluate.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

evaluate.o: evaluate.cpp evaluate.hpp BinaryTree.hpp
	g++ -c evaluate.cpp $(OPCIONS)

utils.o: utils.cpp utils.hpp
	g++ -c utils.cpp $(OPCIONS)

clean:
	rm *.o *.exe
