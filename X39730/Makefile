OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o sumOfValues.o 
	g++ -o program.exe program.o sumOfValues.o 

program.o: program.cpp sumOfValues.hpp
	g++ -c program.cpp $(OPCIONS)

sumOfValues.o: sumOfValues.cpp sumOfValues.hpp
	g++ -c sumOfValues.cpp $(OPCIONS)

clean:
	rm *.o *.exe
    