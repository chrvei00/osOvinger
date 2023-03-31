#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

uint64 format(const char *s) {
    uint64 res = 0;
    while (*s != '\0') {
        res *= 10;
        res += *s - '0';
        s++;
    }
    return res;
}


int main(int c, char *argv[]) {
    if (c < 2 || c > 3)
    {
        exit(1);
    }
    uint64 lol = format(argv[1]);

    int pid;
    if (c == 3)
    {
        pid = atoi(argv[2]);
    }
    else
    {
        pid = getpid();
    }

    uint64 pa = va2pa(lol, pid);

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
