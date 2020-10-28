CHOIX = TABPID
# WAIT NBFILS
# default, if not use $ make mrproper ; make -e CHOIX=NBFILS

CC = gcc

CFLAGS = -Wextra -Wall -g -std=gnu99

SPECIAL_OBJS = n_fork_waitpid.o

EXE = fork\
	fork_arg_sleep\
	exemple_fork\
	exemple_fork_arg2\
	double_child\
	n_fork_waitpid
#	fork_schema_memoire\
#	fork_wait\
#	fork_exit_status

SPECIAL_EXE = n_fork_waitpid

all: $(EXE) $(SPECIAL_EXE)

$(SPECIAL_OBJS): EXTRA_FLAGS := -D$(CHOIX)

%.o: %.c
	@echo [Compiling]: $<
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) -o $@ -c $<

.PHONY: clean mrproper test

clean:
	@rm -f *.o a.out

mrproper: clean
	@rm -f $(EXE) $(SPECIAL_EXE)
	@rm -f *~
