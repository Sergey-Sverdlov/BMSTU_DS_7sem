#define BEGIN_STRING "								\n\
#include <stdio.h> 									\n\
#include <string.h> 								\n\
int main() 											\n\
{													\n\
char unique_id[32];\n\
FILE *f; \n\
if ((f = fopen(\"/var/lib/dbus/machine-id\", \"r\")) == NULL)\n\
{													\n\
printf(\"Don't work on your machine!\");			\n\
return -1;												\n\
}													\n\
fscanf(f, \"%s\", unique_id);						\n\
fclose(f);											\n\
if (!strcmp(unique_id, \"\
"

#define END_STRING "\")) 							\n\
	printf(\"Hello world\");										\n\
else												\n\
printf(\"Access is denied\");						\n\
}													\n\
"

#define PATH_TO_MACHINE_ID "/var/lib/dbus/machine-id"
#define MODE_READ "r"
#define MODE_WRITE "w"
#define LEN_UNIQUE_ID 32
#define PROGRAM_FILE_NAME ".a.c"
#define EXECUTABLE_FILE_NAME "program"
#define OK 0;
