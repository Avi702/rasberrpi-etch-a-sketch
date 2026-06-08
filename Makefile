kall: sketch

sketch: input.o output.o main.o
	cc -o sketch input.o output.o main.o -I ~/include -L ~/lib -lsense -lm

%.o: %.c sketch.h
	cc -c $< -I ~/include

clean:
	rm -rf *.o sketch

run: sketch
	./sketch
