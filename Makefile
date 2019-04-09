cc = gcc
target = fileread
all:$(target)

$(target):main.o custom_math.o
	$(cc) $^ -o $@ 
main.o:main.c
	$(cc) -c $^ -Wall -DDEBUG
custom_math.o:custom_math.c
	$(cc) -c $^ -Wall 
clean:
	rm -rf *.o $(target) *~ fileread.tar.gz install/*
