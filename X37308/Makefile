OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o sumOfValuesEvenPosition.o 
	g++ -o program.exe program.o sumOfValuesEvenPosition.o 

program.o: program.cpp sumOfValuesEvenPosition.hpp
	g++ -c program.cpp $(OPCIONS)

sumOfValuesEvenPosition.o: sumOfValuesEvenPosition.cpp sumOfValuesEvenPosition.hpp
	g++ -c sumOfValuesEvenPosition.cpp $(OPCIONS)

clean:
	rm *.o *.exe
    