obj-m := ukey.o

all: read_key
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -f *.c~
	rm read_key

read_key:
	gcc -o read_key read_key.c
