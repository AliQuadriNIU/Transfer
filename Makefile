stack: main.cpp rational.cpp rational.h stack.h
	g++ -std=c++14 -Wall -Werror -Wextra -pedantic -g -o stack main.cpp rational.cpp

clean:
	rm -f stack

world: clean stack