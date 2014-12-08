CC			:= gcc
CP			:= cp
DEL			:= rm -rf
MV			:= mv
SAY			:= @echo

LIBS			:=  
CFLAGS			:= -O3 
OBJS			:= 
PROGS			:= main

.PHONY			: clean succ
########################################################################
all			: ${PROGS} succ

rebuild			: clean all

run			:
	${SAY} "INPUT:"
	@cat test.txt
	${SAY} "OUTPUT:"
	@cat test.txt | ./main
	${SAY} ""
	${SAY} "CORRECT?"

main			: ${OBJS}
	${CC} ${CFLAGS} $@.c -o $@ ${OBJS} ${LIBS}

#dirTraversal.o		: 
#	${CC} ${CFLAGS} ${*F}.c -c -o $@ ${LIBS}

succ			:
	${SAY} "Complete !" 

clean    : 
	${DEL} ${PROGS}
	${DEL} ${OBJS} 
	${DEL} *~ include/*~ src/*~
	${DEL} *.swp

