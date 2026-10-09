#include "ps2/ps2.h"
#include <malloc.h>
#include <pwd.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/resource.h>

#define PS2_PAGE_SIZE 4096

void
rb_ps2_init(void)
{
}

void *
mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset)
{
    void *p;

    if (!(flags & MAP_ANON) || fd != -1) {
        errno = ENOSYS;
        return MAP_FAILED;
    }
    p = memalign(PS2_PAGE_SIZE, len);
    if (!p) {
        errno = ENOMEM;
        return MAP_FAILED;
    }
    memset(p, 0, len);
    return p;
}

int
munmap(void *addr, size_t len)
{
    free(addr);
    return 0;
}

int
mprotect(void *addr, size_t len, int prot)
{
    return 0;
}

int
getrusage(int who, struct rusage *usage)
{
    clock_t ticks = clock();

    memset(usage, 0, sizeof(*usage));
    if (who == RUSAGE_SELF) {
        usage->ru_utime.tv_sec = ticks / CLOCKS_PER_SEC;
        usage->ru_utime.tv_usec = (ticks % CLOCKS_PER_SEC) * 1000000 / CLOCKS_PER_SEC;
    }
    return 0;
}

void
endpwent(void)
{
}

ssize_t
pread(int fd, void *buf, size_t count, off_t offset)
{
    off_t saved = lseek(fd, 0, SEEK_CUR);
    ssize_t result;

    if (saved < 0 || lseek(fd, offset, SEEK_SET) < 0) {
        return -1;
    }
    result = read(fd, buf, count);
    lseek(fd, saved, SEEK_SET);
    return result;
}

ssize_t
pwrite(int fd, const void *buf, size_t count, off_t offset)
{
    off_t saved = lseek(fd, 0, SEEK_CUR);
    ssize_t result;

    if (saved < 0 || lseek(fd, offset, SEEK_SET) < 0) {
        return -1;
    }
    result = write(fd, buf, count);
    lseek(fd, saved, SEEK_SET);
    return result;
}
