#include<stdio.h>
#include<sys/syscall.h>

long gettime() {
	unsigned int lo, hi;
       	long ret;
       	__asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
       	ret = ((unsigned long long)lo)|(((unsigned long long)hi)<<32);
	return ret;
}

long t1, t2, t3, t4, t5, t6;

void print_times() {
	printf("%ld, %ld, %ld, %ld\n",t2-t1, t3-t2, t5-t4, t6-t5); 
}

void main() {
	int i=0;
	while(i<1000) {
		// sys call part
		t1 = gettime();
//		syscall(548, &t2);
		t3 = gettime();
	
		// user time
		t4 = gettime();
		t5 = gettime();
		t6 = gettime();
	
		print_times();
		i++;
	}	
}
