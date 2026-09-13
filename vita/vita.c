#include "vita/vita.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#if defined(__vita__) || defined(__arm_vita__)

#include <psp2/kernel/processmgr.h>
#include <psp2/kernel/threadmgr.h>
#include <psp2/io/devctl.h>

int _newlib_heap_size_user = 64 * 1024 * 1024;

void
rb_vita_init(void)
{
}

int
dup2(int oldfd, int newfd)
{
    if (oldfd == newfd) {
        return newfd;
    }
    errno = ENOSYS;
    return -1;
}

int
truncate(const char *path, off_t length)
{
    errno = ENOSYS;
    return -1;
}

int
ftruncate(int fd, off_t length)
{
    errno = ENOSYS;
    return -1;
}

int
chown(const char *path, uid_t owner, gid_t group)
{
    errno = ENOSYS;
    return -1;
}

int
fchown(int fd, uid_t owner, gid_t group)
{
    errno = ENOSYS;
    return -1;
}

int
lchown(const char *path, uid_t owner, gid_t group)
{
    errno = ENOSYS;
    return -1;
}

int
fork(void)
{
    errno = ENOSYS;
    return -1;
}

pid_t
waitpid(pid_t pid, int *status, int options)
{
    errno = ECHILD;
    return -1;
}

int
kill(pid_t pid, int sig)
{
    errno = ENOSYS;
    return -1;
}

#else

void
rb_vita_init(void)
{
}

#endif
