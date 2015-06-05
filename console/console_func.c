#ifndef LINE
#include "console.h"
#endif
#include "console_definitions.h"

int is_alpha(char ch)
{
	if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
		return TRUE;
	else 
		return FALSE;
}

int get_str(char* str, int name_length)
{
	const int SUCCESS = 1;
	const int TOO_LONG = 0;
	const int JUST_ENTER = -1;
	int count;
	count = 0;
	while (count<name_length - 1)
	{
		if (count!=0 && str[count - 1] == '\n')
			break;
		str[count++] = getchar();
	}

	if (str[count - 1] != '\n')
	{
		while (getchar() != '\n');
		return TOO_LONG;
	}
	else
	{
		str[count - 1] = '\0';
		if (count == 1)
		{
			return JUST_ENTER;
		}
		return SUCCESS;
	}
}

void print_curr_state(char* path1, char* path2, int p1, int p2)
{
	LINE
		
	(p1)?(printf("File one: %s\n", path1)):(printf("File one haven't chosen\n"));
	(p2)?(printf("File two: %s\n", path2)):(printf("File two haven't chosen\n"));
	printf("\nEnter command: ");
}

void show_help()
{
	LINE
		printf("\t\tHELP\n\n");
	printf("This application compares two codes if they are not copypasted\n");
	printf("\nPRINT:\n");
	printf("   openo <path> - to open file one\n");
	printf("   opent <path> - to open file two\n");
	printf("   check <path> - to check if code copypasted\n");
	printf("   exit - to exit from application\n");
	printf("   help - too see this message again\n");
}

int analyze(char* str, int* p1, int* p2, FILE** f1, FILE** f2, char* path1, char* path2)
{
	int i, j;
	char temp[256];

	i = 0;
	while(str[i] == ' ')
	{
		++i;
	}

	while(is_alpha(str[i]))
	{
		temp[i] = str[i];
		++i;
	}
	temp[i] = '\0';

	for(j = 0;j<COMANDS_AMOUNT;++j)
	{
		if(!strcmp(temp,console[j]))
			break;
	}
	if(j<COMANDS_AMOUNT)
	{
		switch(j)
		{
		case OPENO:
			if(*f1!=NULL)
				fclose(*f1);
			while(str[i] == ' ')
				++i;
			j = 0;
			while(is_alpha(str[i]) || str[i] == ':' || str[i] == '\\' || str[i] == '.')
			{
				path1[j] = str[i];
				++i;
				++j;
			}
			path1[j] = '\0';
			if(*p2 == 1) 
				if( !strcmp(path1, path2))
			{
				printf("\nThis is already opened\n");
				break;
			}
			*f1 = fopen(path1,"rb");
			if(!(*f1))
			{
				printf("\nImpossible to open\n");
			}
			else
			{
				*p1 = 1;
			}
			break;
			
		case OPENT:
			if(*f2!=NULL)
				fclose(*f2);
			while(str[i] == ' ')
				++i;
			j = 0;
			while(is_alpha(str[i]) || str[i] == ':' || str[i] == '\\' || str[i] == '.')
			{
				path2[j] = str[i];
				++i;
				++j;
			}
			path2[j] = '\0';
			if(*p1 == 1) 
				if( !strcmp(path1, path2))
			{
				printf("\nThis is already opened\n");
				break;
			}
			*f2 = fopen(path2,"rb");
			if(!(*f2))
			{
				printf("\nImpossible to open\n");
			}
			else
			{
				*p2 = 1;
			}
			break;
			
		case CHECK:
			break;

		case HELP:
			show_help();
			return HELP;
			break;
		case EXIT:
			return EXIT_CODE;
			break;
		default:
			printf("\nIncorrect comand. Print help, for help\n");
			break;
		}
		

	}
	else printf("\nIncorrect comand. Print help, for help\n");
	return TRUE;
}