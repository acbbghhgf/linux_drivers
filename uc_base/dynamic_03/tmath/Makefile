AR = ar
AR_CFALGS = -r
CC = gcc
SHARE_CFALGS = -shared

src = ./add.c ./mul.c
objs = $(patsubst %.c, %.o, $(src))

static = libtmath.a
dynamic = libtmath.so

static : $(objs)
	$(AR) $(AR_CFALGS) $(static) $(objs)

dynamic : $(objs)
	$(CC) $(SHARE_CFALGS) -o $(dynamic) $(objs)

%.o : %.c
	$(CC) -c -fPIC $^ -o $@

clean:
	rm -rf *.o *.a *.so

