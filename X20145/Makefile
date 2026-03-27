OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o SumBelowAtEvenDepth.o 
	g++ -o program.exe program.o SumBelowAtEvenDepth.o 

program.o: program.cpp SumBelowAtEvenDepth.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

SumBelowAtEvenDepth.o: SumBelowAtEvenDepth.cpp SumBelowAtEvenDepth.hpp BinaryTree.hpp
	g++ -c SumBelowAtEvenDepth.cpp $(OPCIONS)

clean:
	rm *.o *.exe
