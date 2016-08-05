all: clean objects
	@mkdir bin
	@g++ obj/main.o obj/file.o -o bin/Program
	@rm -rf obj
	@printf "\nCompilation finished!\nGo to the 'bin' folder to open the program\n\n"

objects:
	@mkdir obj
	@g++ -c -std=c++11 main.cpp -I include -o obj/main.o
	@g++ -c -std=c++11 src/file.cpp -I include -o obj/file.o

clean:
	@rm -rf bin
	@rm -rf obj

# Easier compilation: g++ -std=c++11 main.cpp src/file.cpp -I include
