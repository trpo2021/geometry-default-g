CFLAGS = -Wall -Wextra -Werror -std=c++17
CPPFLAGS = -MMD
main.o: src
	cd src; g++ $(CFLAGS) $(CPPFLAGS) main.cpp -o main.o; mv main.o ../obj
