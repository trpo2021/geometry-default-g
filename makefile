CFLAGS = -Wall -Wextra -Werror -std=c++17
CPPFLAGS = -MMD

all: bin/geometry

bin/geometry: obj/main.o obj/geometrylib.a 
	cd obj; g++ $(CFLAGS) $(CPPFLAGS) -o geometry main.o  -L. geometrylib.a; mv geometry ../bin; cd ..; find . -name "*.d" -exec mv {} ./obj \;

obj/main.o: src/main.cpp obj/geometrylib.a
	cd src; g++ $(CFLAGS) $(CPPFLAGS) -c main.cpp -o main.o; mv main.o ../obj

obj/geometrylib.a: obj/formatcheck.o obj/figure.o
	cd obj; ar rcs geometrylib.a formatcheck.o figure.o;


obj/figure.o: src/lib/figure.cpp
	cd src/lib; g++ $(CFLAGS) $(CPPFLAGS) -c figure.cpp -o figure.o; mv figure.o ../../obj

obj/formatcheck.o: src/lib/formatcheck.cpp
	cd src/lib; g++ $(CFLAGS) $(CPPFLAGS) -c formatcheck.cpp -o formatcheck.o; mv formatcheck.o ../../obj

run:
	./bin/geometry


.PHONY: clean
clean:
	find . -name "*.d" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
	find . -name "*.a" -exec rm {} \;
	find . -name "geometry" -exec rm {} \;
