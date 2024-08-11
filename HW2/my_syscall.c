#include <linux/syscalls.h>

SYSCALL_DEFINE1(jknuckle_syscall, const char __user *, str)
{   
    long st_size1, count, st_size, res;
    char buf[32];
    char* buf1;
    st_size = strnlen_user(str, 32);
    if ((st_size > 32) || (st_size == 0)) {
        return (long) -1;
    }
    st_size1 = strncpy_from_user(buf, str, st_size);
    if (st_size1 != (st_size - 1)) {
        return (long) -1;
    }
    buf1 = buf;
    printk(KERN_ALERT "before: %s\n", buf1);
    count = 0;
    for (int i = 0; i <= st_size; i++) {
        if ((buf1[i] == 'a') || (buf1[i] == 'e') || (buf1[i] == 'i') || (buf1[i] == 'o') || (buf1[i] == 'u') || (buf1[i] == 'y')) {
            buf1[i] = 'J';
            count++;
        }
    }
    printk(KERN_ALERT "after: %s\n", buf1);
    res = copy_to_user((void*) str, (void*) buf1, st_size);
    if (res == 0) {
        return count;
    }
    return (long) -1;


}
