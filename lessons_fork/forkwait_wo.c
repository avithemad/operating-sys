#include<stdio.h>

void main() {
	int f=fork();

	if (f==0) {
		//child
		wait(NULL);
		printf("Hello\n");
	} else {
		// parent 
		printf("Goodbye\n");
	}
}
