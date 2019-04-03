cc = gcc
target = fileread
all:$(target)

$(target):main.o
	$(cc) $^ -o $@ 
main.o:main.c
	$(cc) -c $^ -Wall -DDEBUG

clean:
	rm -rf *.o $(target) *~ fileread.tar.gz install/*
