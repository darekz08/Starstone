
#include <libstar.h>

void sleep(uint64_t ms) {
	
	struct timespec tm;
    tm.tv_sec = ms / 1000;
    tm.tv_nsec = (ms - tm.tv_sec * 1000) * 1000000;

    sys_nanosleep(&tm, NULL);
	
}

void std_print(char* str) {
	
	sys_write(1, str, strlen(str));
	
}

void std_clear() {
	
	std_print("\033[H\033[J");
	
}

int execute_process(char *fn) {
	
	long pid = sys_fork();
	
	if (!pid) {
		
		char *argv[2];
		argv[0] = fn;
		argv[1] = 0;
		
		char *envp[1];
		envp[0] = 0;
		
		return sys_execve(fn, argv, envp);
		
	}
	
}