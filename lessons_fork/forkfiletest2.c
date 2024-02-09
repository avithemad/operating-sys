#include<stdio.h>
#include<fcntl.h>

void main() {
	int fd = open("shared2.txt", O_CREAT | O_WRONLY, 0644);

	if (fd == -1) {
		printf("Error opening file \n"); 
		exit(0);
	}
	int f = fork();

	if (f == 0) {
		char* data = "hello parent\n";
		printf("Parent is writing %d characters\n", strlen(data));
		write(fd, data, strlen(data));
		close(fd);
	} else {
		char* data = "hello child\n";
		printf("Child is writing %d characters\n", strlen(data));
		write(fd, data, strlen(data));
		close(fd);
	}
}
