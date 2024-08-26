This repository contains all files I changed or added throughout the process of created a syscall in a fully working Linux Kernel. This includes the main Makefile that runs on boot,
another makefile that compiled my syscall, the syscall table, the syscall header file, and the syscall itself. Along with this syscall, I created a user program that interacts with
it. The syscall converts a string provided by user space to a different string with slight modifications, and sends it back to user space. From this, I learned how a syscall is 
recognized by the kernel, how it is compiled by the kernel, and how the kernel space safely interacts with user space.
