OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o copy.o 
	g++ -o program.exe program.o copy.o 

program.o: program.cpp copy.hpp
	g++ -c program.cpp $(OPCIONS)

copy.o: copy.cpp copy.hpp
	g++ -c copy.cpp $(OPCIONS)

clean:
	rm *.o *.exe
    