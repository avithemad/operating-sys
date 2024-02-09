#include<iostream>
#include<string>
#include<unistd.h>
#include <sys/wait.h>

void type_prompt();

int main() {
	while(true) {
		char bin[100];
		int status;

		if (fork()!=0) {
			// spawns child programs
			waitpid(-1, &status, 0);
		} else {
			// Parent program which is the shell
			type_prompt();
			scanf("%s", bin);
			int res_code = execve(bin, 0, 0);
			std::cout << "Res_code : " << res_code << std::endl;	
		}
	}
	return 0;
}

void type_prompt() {
	std::cout << "$" ;
}
