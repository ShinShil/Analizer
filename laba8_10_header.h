#define _CRT_SECRE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define IN_BLOCK_DEVIDE '$'
#define BLOCK_DEVIDE '#'
#define NAME_END '!'
#define TRUE 1
#define FALSE 0

typedef enum
{
	CHAR = 0, INT = 1, DOUBLE = 2,
	IF = 3, ELSE = 4,
	FOR = 5, WHILE = 6, DO = 7,
	SCANF = 8,
	PRINTF = 9
}token;

extern char token_names[10][10];

typedef struct
{
	char** t;
	char** f;
}cond;

typedef struct
{
	char* name;
	int type;
	int lvl;
	union 
	{
		int a;
		char b;
		double c;

	}real_value;
}val;

typedef struct
{
	char* name;
	int lvl;
}other;

typedef struct
{
	char** t;
	char** f;
}loop;

/*token_work*/
char* get_token_name(FILE* f, int* lvl);
int take_size_word(FILE* f);
int is_alpha(char ch);
void miss_spaces(FILE* f);
char take_char_f(FILE* f);
int first_letter_token(FILE* f);
void make_token_arrays(FILE* f, val* vals, other* others, cond* conds, loop* loops);
val* make_val(FILE* f, int num_token_name, int lvl);
char* make_word(FILE*f);
int feof_star(FILE* f); //!!!!!

/*array_work*/
void copy_val(val* v1, val* v2);
void add_val(val** arr_val, val* value);
void fwrite_arr_val(FILE* f, val* vals);