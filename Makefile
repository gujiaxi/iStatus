CC     = cc
CFLAGS = -O2 -Wall
INC    = -framework IOKit
PREFIX = /Users/jiaxi/Downloads
EXEC   = osx-cpu-temp

build : $(EXEC)

clean : 
	rm $(EXEC)

$(EXEC) : smc.c
	$(CC) $(CFLAGS) $(INC) -o $@ $?

install : $(EXEC)
	install -d $(EXEC) $(PREFIX)/bin/$(EXEC)
