
#include <libstar.h>

uint64_t sys_read(uint64_t fd, char* buf, uint64_t size) {
	
	return _syscall(SYS_read, (void *)fd, buf, (void *)size, 0, 0, 0);
	
}

uint64_t sys_write(uint64_t fd, char* buf, uint64_t size) {
	
	return _syscall(SYS_write, (void *)fd, buf, (void *)size, 0, 0, 0);
	
}

uint64_t sys_open(char* fn, int flags) {
	
	return _syscall(SYS_open, fn, (void *)(long)flags, 0, 0, 0, 0);
	
}

uint64_t sys_close(uint64_t fd) {
	
	return _syscall(SYS_close, (void*)fd, 0, 0, 0, 0, 0);
	
}

uint64_t sys_nanosleep(struct timespec *req, struct timespec *rem) {
	
	return _syscall(SYS_nanosleep, req, rem, 0, 0, 0, 0);
	
}

int64_t sys_fork() {
	
	return _syscall(SYS_fork, 0, 0, 0, 0, 0, 0);
	
}

int64_t sys_execve(char *filename, char **argv, char **envp) {
	
	return _syscall(SYS_execve, filename, argv, envp, 0, 0, 0);
	
}

uint64_t sys_reboot() {
	
	return _syscall(SYS_reboot, (void *)0xfee1dead, (void *)672274793, (void*)0x1234567, 0, 0, 0);
	
}
