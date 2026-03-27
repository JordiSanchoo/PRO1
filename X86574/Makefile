OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o reverse.o 
	g++ -o program.exe program.o reverse.o 

program.o: program.cpp reverse.hpp
	g++ -c program.cpp $(OPCIONS)

reverse.o: reverse.cpp reverse.hpp
	g++ -c reverse.cpp $(OPCIONS)

clean:
	rm *.o *.exe
    