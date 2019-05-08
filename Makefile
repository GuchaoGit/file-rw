#cc = mipsel-linux-gcc
cc = gcc
target = fileread
CFLAGS = 
all:$(target)

$(target):main.o custom_math.o utils.o cJSON.o
	$(cc) $^ -o $@ 
main.o:main.c
	$(cc) -c $^ -Wall -DDEBUG $(CFLAGS)
custom_math.o:custom_math.c 
	$(cc) -c $^ -Wall $(CFLAGS)
utils.o:utils.c
	$(cc) -c $^ -Wall $(CFLAGS)
cJSON.o:cJSON.c
	$(cc) -c $^ -Wall -std=c99 $(CFLAGS)
clean:
	rm -rf *.o $(target) *~ fileread.tar.gz install/*
