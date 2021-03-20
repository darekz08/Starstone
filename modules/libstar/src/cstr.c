
#include <libstar.h>

int strlen(char* str) {

	int count = 0;
	while (*str++) count++;
	return count;

}

bool str_eq(char* str1, char* str2) {
	
	char c1 = *str1;
	char c2 = *str2;
	
	for(; c1 != 0 && c2 != 0; c1 = *(++str1), c2 = *(++str2)) {
		
		if(c1 != c2) return false;
		
	}
	
	return true;
	
}