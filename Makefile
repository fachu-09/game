all:
	cc *.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ./bin/game
clean:
	rm bin/**