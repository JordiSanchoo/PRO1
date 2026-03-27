OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o push_back.o 
	g++ -o program.exe program.o push_back.o 

program.o: program.cpp push_back.hpp
	g++ -c program.cpp $(OPCIONS)

push_back.o: push_back.cpp push_back.hpp
	g++ -c push_back.cpp $(OPCIONS)

clean:
	rm *.o *.exe
    