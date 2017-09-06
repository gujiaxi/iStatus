CC      = cc
CFLAGS  = -O2 -Wall
INCLUDE = -framework IOKit -framework CoreFoundation
PREFIX  = /usr/local
EXEC    = istatus

all: $(EXEC)

$(EXEC): istatus.c smc.c bat.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $?

clean:
	rm -rf *.o $(EXEC)

.PHONY: all $(EXEC) clean
