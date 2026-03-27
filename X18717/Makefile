OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o copyEvenPos.o 
	g++ -o program.exe program.o copyEvenPos.o 

program.o: program.cpp copyEvenPos.hpp
	g++ -c program.cpp $(OPCIONS)

copyEvenPos.o: copyEvenPos.cpp copyEvenPos.hpp
	g++ -c copyEvenPos.cpp $(OPCIONS)

clean:
	rm *.o *.exe
    