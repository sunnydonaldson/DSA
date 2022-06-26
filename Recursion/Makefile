include ../helpers/Makefile 

# outputs = exponent factorial head-recursion nested-recursion recursion-with-static
# sum-of-natural-numbers tail-recursion tree-recursion

srcs = $(wildcard *.c)
outputs = $(basename $(srcs))
libs = ../helpers/iohelper.o

# Maps a .c file to a .o (object) file
.c.o:
	cc -c $< -o $@

# $(objs):

# $(srcs): $(libs) $@
# 	cc $^ $@ -o $(basename $@)


# Links the .o file (which gets compiled from the .c file above) 
$(outputs): $(libs) $@
	cc $^ $@.c -o $@

clean :
	rm $(basename $(srcs))