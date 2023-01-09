# Makefile for "usage"

CC=/usr/bin/gcc
BINDIR=/usr/local/bin

all:	usage usage.pl

usage.pl:	usage.pl.in
	@echo "Making usage.pl..."; \
	cat usage.pl.in | \
	sed "s:#_BINDIR_#:$(BINDIR):g" | \
	cat > usage.pl; \
	chmod +x usage.pl

usage:	usage.c
	$(CC) usage.c -o usage

install: usage usage.pl
	cp usage usage.pl $(BINDIR)
	chown root:bin $(BINDIR)/usage
	chmod u+s $(BINDIR)/usage

clean:
	rm -f usage.pl usage


