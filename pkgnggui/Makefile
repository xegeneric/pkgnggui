# pkgnkgui Makefile
#
# pkgnggui is being developed on FreeBSD -CURRENT
#
# tylerjkuck@gmail.com

# VARS
CC	=	clang
SRCS	=	./src/main.c

#Build
main: $(SRCS)
	$(CC) -o pkgnggui ./src/main.c `pkg-config --libs --cflags gtk+-2.0`
