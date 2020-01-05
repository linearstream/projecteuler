AT=@
CC=gcc
CFLAGS=-Wall
EXE=multiples_3_5
DEPS=$(EXE).h
OBJ=$(EXE).o

%.o: %.c $(DEPS)
	${AT}${CC} ${CFLAGS} -c -o $@ $<

$(EXE): $(OBJ)
	${AT}${CC} ${CFLAGS} -o $@ $^

clean:
	${AT}rm -f ${EXE} ${EXE}.o
