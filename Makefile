build:
	gcc -Wall -Werror -Wextra -pedantic ./src/*.c -lm -o maze `sdl2-config --cflags --libs`;

run:
	./maze maps/map1.txt;

clean:
	rm maze;
