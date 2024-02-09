#include<stdio.h>
#include<stdlib.h>

long gettime() {
	unsigned int lo, hi;
        long ret;
        __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
        ret = ((unsigned long long)lo)|(((unsigned long long)hi)<<32);
        return ret;
}

long t1, t2, t3;
void main() {
	int n=1000000;
	int *ar = (int*) malloc(sizeof(int)*n);
	t1 = gettime();
	for (int i=0;i<n;i++) {
		ar[i] = ar[i]+ar[(i+6)%n];
		t2 = gettime();
		printf("%ld\n", t2-t1);
		t1 = t2;
		if (i%1000 == 0) {
			syscall(549, &t3);
		}
	}
	free(ar);
}
