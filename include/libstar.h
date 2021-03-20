
#pragma once
#include <syscall.h>
#include <time.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdbool.h>

int strlen(char* str);
bool str_eq(char* str1, char* str2);

void sleep(uint64_t ms);
void std_print(char* str);
int execute_process(char *fn);

// SYSCALLS HERE!

long _syscall(int id, void* a0, void* a1, void* a2, void* a3, void* a4, void* a5);

uint64_t sys_read(uint64_t fd, char* buf, uint64_t size); // SYSCALL 0x000
uint64_t sys_write(uint64_t fd, char* buf, uint64_t size); // SYSCALL 0x001
uint64_t sys_open(char* fn, int flags); // SYSCALL 0x002
uint64_t sys_close(uint64_t fd); // SYSCALL 0x003
uint64_t sys_nanosleep(struct timespec *req, struct timespec *rem); // SYSCALL 0x023
int64_t sys_fork(); // SYSCALL 0x39
int64_t sys_execve(char *filename, char **argv, char **envp);
uint64_t sys_reboot(); // SYSCALL 0x0a9