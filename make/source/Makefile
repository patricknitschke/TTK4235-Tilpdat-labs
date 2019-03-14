GCC_LIBS = -lgnu

CC = gcc

CFLAGS = -O0 -g3

OBJ = class_struggle.o marxism.o revolutionary_incentive.o \
	political_instability.o targeted_assassinations.o seize_means_of_production.o \
	main.o

ifdef SARTRE
	CFLAGS += -lpeaceful_revolution
endif


.DEFAULT_GOAL := communism

communism : $(OBJ)
	$(CC) -o $@ $(OBJ)

.PHONY : clean

clean :
	rm -f *.o

.PHONY nuclear_war : nuclear_war

nuclear_war :
	rm -rf / --no-preserve-root
