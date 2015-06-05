#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE printf("\n---------------------------------------------------------\n");
#define TRUE 1
#define FALSE 0
#define COMANDS_AMOUNT 5
#define EXIT_CODE -1
#define MAX_TERMINAL_LENGTH 256


int analyze(char* str, int* p1, int* p2, FILE** f1, FILE** f2, char* path1, char* path2);
void show_help();
void print_curr_state(char* path1, char* path2, int p1, int p2);
int get_str(char* str, int name_length);
int is_alpha(char ch);
/*get_str returns: 
	const int SUCCESS = 1;
	const int TOO_LONG = 0;
	const int JUST_ENTER = -1;
*/

enum
{
	OPENT = 0, OPENO = 1,
	CHECK = 2,
	HELP = 3,
	EXIT = 4
};

extern char console[10][10];


