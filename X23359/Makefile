OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o merge.o 
	g++ -o program.exe program.o merge.o 

program.o: program.cpp merge.hpp
	g++ -c program.cpp $(OPCIONS)

merge.o: merge.cpp merge.hpp
	g++ -c merge.cpp $(OPCIONS)

clean:
	rm *.o *.exe
    