#ifndef LINE
#include "console.h"
#endif
extern char console[10][10];

int main(void)
{
	/*Firstly make info file*/
	FILE* f1, *f2;
	char str[MAX_TERMINAL_LENGTH], path1[MAX_TERMINAL_LENGTH], path2[MAX_TERMINAL_LENGTH];
	int p1, p2;

	p1 = 0;
	p2 = 0;
	f1 = NULL;
	f2 = NULL;
	printf("\n\t\\\\\\\\\\\\\\\\\\Laba 8\\\\\\\\\\\\\\\\\\\n");
	show_help();
	for(;;)
	{
		print_curr_state(path1, path2, p1, p2);
		switch(get_str(str, MAX_TERMINAL_LENGTH+2))
		{
		case 0:
			printf("\nToo long cpmmand\n");
			continue;
		case -1:
			printf("\nEmpty command\n");
			continue;
		}
		if(analyze(str, &p1, &p2, &f1, &f2, path1, path2) == EXIT_CODE)
		{
			if(f1!=NULL)
				fclose(f1);
			if(f2!=NULL)
				fclose(f2);
			printf("\n\nGood bye!!!\n\n");
			return 0;
		}
	}
}