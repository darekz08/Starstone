
#include <libstar.h>

uint64_t console_fd = 0;

void console_open() {
	
	console_fd = sys_open("/dev/console", O_RDWR | O_NDELAY);
	
}

char console_read() {
	
	char c = 0;
	while(!sys_read(console_fd, &c, 1)) {
		
		struct timespec ts;
		ts.tv_sec = 0;
		ts.tv_nsec = 10000;
		sys_nanosleep(&ts, NULL);
		
	}
	
	return c;
	
}

void console_write(char c) {
	
	sys_write(console_fd, &c, 1);
	
}

int read_line(char* buf, int size) {
	
	int i = 0;
	
	for(; i<size; i++) {
		
		char c = console_read();
		
		if(c == 0) {
			
			i--;
			continue;
			
		}
		
		console_write(c);
		buf[i] = c;
		
		if(c == '\b') {
			
			i--;
			buf[i] = 0;
			
		}
		if(c == '\n') {
			
			buf[i] = 0;
			return i;
			
		}
		
	}
	
	return i;
	
}

void main() {
	
	std_clear();
	std_print("StarTerm 1.0\n");
	
	console_open();
	
	while(1) {
		
		std_print(" >>> ");
		
		char buf[1024];
		read_line(buf, sizeof(buf));
		std_print("\n");
		
		if(strcmp(buf, "reboot") == 0) {
			
			std_print("REBOOTING");
			sleep(1000);
			sys_reboot();
			
		}
		
	}
	
	while (1);
	
}