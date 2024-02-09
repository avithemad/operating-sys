#include<stdio.h>

void main() {
	int f = fork();
	int exitStatus;

	if (f==0) {// this is child process
		printf("In child process\n");
		exit(1);
	} else { // this is parent process
		wait(&exitStatus);
		printf("Child exit status %d\n", exitStatus);
		exit(0);
	}
}
