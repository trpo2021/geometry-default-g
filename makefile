CFLAGS = -Wall -Wextra -Werror -std=c++17
CPPFLAGS = -MMD


bin/main: obj/main.o src/lib/geometrylib.a 
	mkdir bin; cd obj; g++ $(CFLAGS) $(CPPFLAGS) -o main main.o  -L. ../src/lib/geometrylib.a; mv main ../bin;


obj/main.o: src/main.cpp src/lib/geometrylib.a
	mkdir obj; cd src; g++ $(CFLAGS) $(CPPFLAGS) -c main.cpp -o main.o; mv main.o ../obj

src/lib/geometrylib.a: obj/formatcheck.o obj/figure.o
	cd obj; ar rcs geometrylib.a formatcheck.o figure.o; mv geometrylib.a ../src/lib


obj/figure.o: src/lib/figure.cpp
	cd src/lib; g++ $(CFLAGS) $(CPPFLAGS) -c figure.cpp -o figure.o; mv figure.o ../../obj


obj/formatcheck.o: src/lib/formatcheck.cpp
	mkdir obj; cd src/lib; g++ $(CFLAGS) $(CPPFLAGS) -c formatcheck.cpp -o formatcheck.o; mv formatcheck.o ../../obj

run:
	./bin/main

clean:
	cd obj; rm -rf *.o
