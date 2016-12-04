mtest : mtest.o foo.o boo.o bar.o
	gcc -o mtest mtest.o foo.o boo.o bar.o

mtest.o : mtest.c
	gcc -c mtest.o mtest.c

foo.o : foo.c
	gcc -c -o foo.o foo.c

boo.o : boo.c
	gcc -c -o boo.o boo.
	
bar.o : bar.c
	gcc -c -o bar.o bar.c

clean : rm *.o mtest

