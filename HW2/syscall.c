#define _GNU_SOURCE
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv) {
    char str1[] = "abcdefghijklmnopqrstuvwxyz";
    printf("str1 before: %s\n", str1);
    long j = syscall(451, str1);
    printf("syscall result: %ld\n", j);
    printf("str1 after: %s\n", str1);
    char str2[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    printf("str2 before: %s\n", str2);
    long j2 = syscall(451, str2);
    printf("syscall result: %ld\n", j2);
    printf("str2 after: %s\n", str2);
    return 0;
}