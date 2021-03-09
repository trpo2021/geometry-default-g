CFLAGS = -Wall -Wextra -Werror -std=c++17
CPPFLAGS = -MMD

all: bin/geometry

bin/geometry: obj/main.o src/lib/geometrylib.a 
	mkdir bin; cd obj; g++ $(CFLAGS) $(CPPFLAGS) -o geometry main.o  -L. ../src/lib/geometrylib.a; mv geometry ../bin;


obj/main.o: src/main.cpp src/lib/geometrylib.a
	cd src; g++ $(CFLAGS) $(CPPFLAGS) -c main.cpp -o main.o; mv main.o ../obj

src/lib/geometrylib.a: obj/formatcheck.o obj/figure.o
	cd obj; ar rcs geometrylib.a formatcheck.o figure.o; mv geometrylib.a ../src/lib


obj/figure.o: src/lib/figure.cpp
	cd src/lib; g++ $(CFLAGS) $(CPPFLAGS) -c figure.cpp -o figure.o; mv figure.o ../../obj


obj/formatcheck.o: src/lib/formatcheck.cpp
	mkdir obj; cd src/lib; g++ $(CFLAGS) $(CPPFLAGS) -c formatcheck.cpp -o formatcheck.o; mv formatcheck.o ../../obj

run:
	./bin/geometry

clean:
	find . -name "*.d" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
