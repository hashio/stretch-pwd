PREFIX=/usr/local
OBJS=stretch-pwd.o
LIBS=-lc
INSTALL=install -s

.c.o:
	$(CC) -O2 -c $<

all: stretch-pwd

stretch-pwd: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

install: stretch-pwd
	$(INSTALL) $< $(PREFIX)/bin

clean:
	rm -f *.o stretch-pwd
