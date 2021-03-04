CFLAGS = -Wall -Wextra -Werror -std=c++17
CPPFLAGS = -MMD


bin/main: obj/main.o obj/figure.o src/lib/formatcheck.a 
	mkdir bin; cd obj; g++ $(CFLAGS) $(CPPFLAGS) -o main figure.o main.o  -L. ../src/lib/formatcheck.a; mv main ../bin


obj/main.o: src/main.cpp src/lib/formatcheck.a
	cd src; g++ $(CFLAGS) $(CPPFLAGS) -c main.cpp -o main.o; mv main.o ../obj

obj/figure.o: src/lib/figure.cpp
	cd src/lib; g++ $(CFLAGS) $(CPPFLAGS) -c figure.cpp -o figure.o; mv figure.o ../../obj

	
src/lib/formatcheck.a: obj/formatcheck.o
	cd obj; ar rcs formatcheck.a formatcheck.o; mv formatcheck.a ../src/lib

obj/formatcheck.o: src/lib
	cd src/lib; g++ $(CFLAGS) $(CPPFLAGS) -c formatcheck.cpp -o formatcheck.o; mv formatcheck.o ../../obj

run:
	./bin/main

clean:
	cd obj; rm -rf *.o
