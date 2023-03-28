#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

uint64 str_to_uint64(const char *s) {
    uint64 result = 0;
    while (*s != '\0') {
        result *= 10;
        result += *s - '0';
        s++;
    }
    return result;
}


int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3)
    {
        fprintf(2, "Usage: vatopa virtual_address [pid]\n");
        exit(1);
    }

    uint64 va = str_to_uint64(argv[1]);

    int pid;
    if (argc == 3)
    {
        pid = atoi(argv[2]);
    }
    else
    {
        pid = getpid();
    }

    uint64 pa = va2pa(va, pid);

    if (pa == 0)
    {
        printf("0x0\n");
    }
    else
    {
        printf("0x%x\n", pa);
    }

    exit(0);
}
