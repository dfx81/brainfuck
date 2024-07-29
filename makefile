all: clean compile run

build: build-linux build-win

build-win:
	@mkdir -p bin
	@x86_64-w64-mingw32-gcc -Wall -g -Wextra -Werror -pedantic -O3 -s -std=c11 ./src/*.c -o bin/bf.exe

build-linux:
	@mkdir -p bin
	@gcc -Wall -g -Wextra -Werror -pedantic -O3 -s -std=c11 ./src/*.c -o bin/bf

compile:
	@mkdir -p bin
	@gcc -Wall -g -Wextra -Werror -pedantic -std=c11 ./src/*.c -o bin/bf

run:
	@clear
	@bin/bf hello.bf

clean:
	@rm -rf bin
	@clear