OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o replace0sWithAboveSumDepthEven.o 
	g++ -o program.exe program.o replace0sWithAboveSumDepthEven.o 

program.o: program.cpp replace0sWithAboveSumDepthEven.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

replace0sWithAboveSumDepthEven.o: replace0sWithAboveSumDepthEven.cpp replace0sWithAboveSumDepthEven.hpp BinaryTree.hpp
	g++ -c replace0sWithAboveSumDepthEven.cpp $(OPCIONS)

clean:
	rm *.o *.exe
