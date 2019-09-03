ifdef GPROF
CFLAGS += -O1 -pg
GPROFFLAG = -pg
else
CFLAGS += -O1
endif

CFLAGS += -fopenmp -I. 
ifndef $(SRCFILE)
SRCFILE=parallel.c	
endif

EXEC_FILE=Test
OBJ_FILE=$(patsubst %.c,%.o,$(SRCFILE))

all:  $(EXEC_FILE)

$(EXEC_FILE): $(OBJ_FILE) main.o sequential.o
	gcc -o $(EXEC_FILE) -fopenmp $(OBJ_FILE) main.o sequential.o -lm $(GPROFFLAG) 

$(OBJ_FILE): $(SRCFILE) $(HEADERS)
	gcc $(CFLAGS) -c $(SRCFILE)

main.o: main.c $(HEADERS)
	gcc $(CFLAGS) -c main.c

sequential.o: sequential.c $(HEADERS)
	gcc $(CFLAGS) -c sequential.c

clean:
	rm -f $(EXEC_FILE) $(OBJ_FILE) main.o sequential.o gmon.out
