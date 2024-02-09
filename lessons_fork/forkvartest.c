#include<stdio.h>

int main() {
	int x=10;
	int f = fork();

	//parent 
	if (f == 0) {
		x = 11;
		printf("parent: %d\n", x);
	} else {
		x = 122;
		printf("child: %d\n", x);
	}
	return 0;
}
