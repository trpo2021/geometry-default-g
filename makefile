PATH  := src:$(PATH)
main:
	$(PATH)g++ -Wall -Werror -std=c++17 main.cpp -o main