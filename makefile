project3Exe: main.o champion.o
	gcc -std=c99 main.o champion.o -o project3Exe

main.o: main.c champion.h
	gcc -c main.c

route-records.o: champion.c champion.h
	gcc -c champion.c

clean:
	rm -rf *.o project3Exe

