# Makefile du tp arg env id
# ms : version du 26 septembre 2019
#

DEBUG = no 		# ou make -e DEBUG=yes
SHELL = /bin/bash 	# pour avoir la bonne syntaxe dans les tests
CC = gcc

ifeq ($(DEBUG),yes)
	CFLAGS = -Wextra -Wall -g -std=gnu11
else
	CFLAGS = -O2 -std=gnu11
endif

EXECUTABLES = echoargenv \
	echoargenviron \
	echoargenviron_2\



all :	$(EXECUTABLES)           # Regle implicite
	@echo "debug:" $(DEBUG)

clean :
	@rm -f core *.o *.out *~
	@rm -f $(EXECUTABLES)

test:
	@echo "--------------------------------------------------"
	sh test_echoargenv.sh
	@echo "--------------------------------------------------"
	./echoargenv toto HOSTNAME


