#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include "constants.h"


void get_machine_id(char unique_id[LEN_UNIQUE_ID])
{
	FILE *f = fopen(PATH_TO_MACHINE_ID, MODE_READ);
	fscanf(f, "%s", unique_id);
	fclose(f);
}

void create_c_file()
{
	FILE *f = fopen(PROGRAM_FILE_NAME, MODE_WRITE);

	char unique_id[LEN_UNIQUE_ID];
	get_machine_id(unique_id);

	fprintf(f, "%s", BEGIN_STRING);
	fprintf(f, "%s", unique_id);
	fprintf(f, "%s", END_STRING);

	fclose(f);
}

void compile()
{
	int child_id;

	if ((child_id = fork()) == -1)
	{
		return;
	}	
	else if (!child_id)
	{
		// child process
		execlp("gcc", "gcc", PROGRAM_FILE_NAME, "-ldl", "-o", EXECUTABLE_FILE_NAME, "-L.", "-Wl,-rpath,.", NULL);
	}
	
	if (child_id)
	{
		// main process
		int status;
		wait(&status);
	}
} 		

int main(void)
{
	create_c_file();
	compile();

	return OK;
}
