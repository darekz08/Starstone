
#include <libstar.h>

void main() {
	
	std_clear();
	std_print("Starstone 1.0\nRunning StarTerm...");
	
	execute_process("/bin/starterm");
	
	while (1);
	
}