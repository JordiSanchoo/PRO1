OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o suma_nivells.o 
	g++ -o program.exe program.o suma_nivells.o 

program.o: program.cpp suma_nivells.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

suma_nivells.o: suma_nivells.cpp suma_nivells.hpp BinaryTree.hpp
	g++ -c suma_nivells.cpp $(OPCIONS)

clean:
	rm *.o *.exe
