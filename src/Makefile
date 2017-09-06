CC      = cc
CFLAGS  = -O2 -Wall
INCLUDE = -framework IOKit
PREFIX  = /usr/local
EXEC    = istatus

all: $(EXEC)

$(EXEC): smc.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $?

clean:
	rm -rf *.o $(EXEC)

.PHONY: all $(EXEC) clean
