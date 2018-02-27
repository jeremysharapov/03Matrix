all: display.c main.c draw.c matrix.c draw.h ml6.h display.h matrix.h	
	gcc -g display.c main.c draw.c matrix.c draw.h ml6.h display.h matrix.h 
	./a.out


clean:
	rm a.out *.gch
