main: src
	cd src && g++ -Wall -Werror -std=c++17 main.cpp -o main; mv main ..