AT=@
CC=gcc
CFLAGS=-Wall
EXE=sum_multiples_less_than_max
DEPS=$(EXE).h
OBJ=$(EXE).o

%.o: %.c $(DEPS)
	${AT}${CC} ${CFLAGS} -c -o $@ $<

$(EXE): $(OBJ)
	${AT}${CC} ${CFLAGS} -o $@ $^

clean:
	${AT}rm -f ${EXE} ${EXE}.o
