PACKAGE = istatus
PREFIX = /usr/local

all clean:
	cd src && $(MAKE) $@

install: all
	install -d $(PREFIX)/bin
	install src/$(PACKAGE) $(PREFIX)/bin

.PHONY: all clean install
