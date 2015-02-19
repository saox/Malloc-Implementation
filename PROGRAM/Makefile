SRC	= malloc.h malloc.c tstalgorithms.c   \
	  tstextreme.c tstmalloc.c  tstmemory.c tstrealloc.c tstmerge.o mytest.c

OBJ	= malloc.o tstalgorithms.o \
	  tstextreme.o tstmalloc.o  tstmemory.o tstrealloc.o tstmerge.o mytest.o

BIN	= t0 t1 t2 t3 t4 t5 t6

CFLAGS	= -g -Wall -ansi -DSTRATEGY=4

XFLAGS	= -g -Wall -DSTRATEGY=1

#CC	= gcc -ansi -pedantic -Wall -g -pipe -O -pg
CC	= gcc 

all: cleanall $(BIN)
	bash ./RUN_TESTS

t0: tstmerge.o malloc.o $(X)
	$(CC) $(CFLAGS) -o  $@ tstmerge.o malloc.o $(X)

t1: tstalgorithms.o malloc.o $(X)
	$(CC) $(CFLAGS) -o  $@ tstalgorithms.o malloc.o $(X)

t2: tstextreme.o malloc.o $(X)
	$(CC) $(CFLAGS) -o $@  tstextreme.o malloc.o $(X)

t3: tstmalloc.o  malloc.o $(X)
	$(CC) $(CFLAGS) -o $@ tstmalloc.o  malloc.o $(X) 

t4: tstmemory.o malloc.o $(X)
	$(CC) $(CFLAGS) -o $@ tstmemory.o malloc.o $(X)

t5: tstrealloc.o malloc.o $(X)
	$(CC) $(CFLAGS) -o $@ tstrealloc.o malloc.o $(X)
	
t6: mytest.o malloc.o $(X)
	$(CC) $(CFLAGS) -o $@ mytest.o malloc.o $(X)


clean:
	\rm -f $(BIN) $(OBJ) core

cleanall: clean
	\rm -f *~

0: cleanall $(BIN) 
	./t0
1: cleanall $(BIN) 
	./t1
2: cleanall $(BIN) 
	./t2
3: cleanall $(BIN) 
	./t3
4: cleanall $(BIN) 
	./t4	
5: cleanall $(BIN) 
	./t5	
6: cleanall $(BIN) 
	./t6	