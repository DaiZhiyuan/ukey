#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

#define PAGE_SIZE     4096

int main (int argc, char **argv)
{
    int fd;
    char *address = NULL;

    fd = open("/dev/ukey", O_RDWR);
    if (fd < 0) {
        perror("Open call failed");
        return -1;
    }

    address = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (address == MAP_FAILED) {
        perror ("mmap operation failed");
        return -1;
    }

    int ukey = open("./UKEY", O_WRONLY|O_CREAT|O_TRUNC);
    write(ukey, address, PAGE_SIZE);
        
    close(ukey);
    close(fd);
  
    return 0;
}
