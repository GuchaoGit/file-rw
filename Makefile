cc = mipsel-linux-gcc
#cc = gcc
target = fileread
all:$(target)

$(target):main.o custom_math.o utils.o cJSON.o
	$(cc) $^ -o $@ 
main.o:main.c
	$(cc) -c $^ -Wall -DDEBUG 
custom_math.o:custom_math.c 
	$(cc) -c $^ -Wall 
utils.o:utils.c
	$(cc) -c $^ -Wall
cJSON.o:cJSON.c
	$(cc) -c $^ -Wall -std=c99 
clean:
	rm -rf *.o $(target) *~ fileread.tar.gz install/*
