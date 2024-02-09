#include<stdio.h>

void main() {
	FILE *fp;
	fp = fopen("shared.txt", "w");

	int f = fork();

	// parent
	if (f == 0) {
		printf("Attempting to write in parent\n");
		fprintf(fp, "From parent\n");
		fclose(fp);
	} else {
		printf("Attempting to write in child\n");
		fprintf(fp, "From child\n");
		fclose(fp);
	}
}
