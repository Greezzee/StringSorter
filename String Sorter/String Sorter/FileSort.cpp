#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "FileIO.h"
#include "StringCompare.h"
#include "Text.h"


int main()
{
	setlocale(LC_ALL, ".ACP");

	char InFileName[FILENAME_MAX] = "";
	printf("Welcome to File Sorter v0.1\nEnter File Name:\nEnter: ");
	scanf("%s", InFileName);

	char OutFileName[] = "out.txt";
	long stringsCount = 0;
	char* text = ReadFile(InFileName, &stringsCount);

	if (text == NULL)
	{
		printf("Error in file reading\nQuitting...\n");
		return 0;
	}

	printf ("Enter sorting type:\n"
			"1 - alphabeth sort\n"
			"2 - alphabeth from end of string\n"
			"3 - alphabeth from end of string, ignore punctuation\n"
			"4 - string lenght sort, alphabeth if equal\n"
			"5 - string lenght sort, alphabeth from end of string if equal\n"
			"6 - string lenght sort, alphabeth from end of string, ignore punctuation, if equal\n"
			"q - quit\n"
			"Enter: ");

	char SortType = '\0';
	scanf("%*c%c", &SortType);
	int (*compareFunc) (const void*, const void*);
	switch (SortType)
	{
	case '1':
		compareFunc = AlphaCompare;
		break;
	case '2':
		compareFunc = AlphaCompareFromEnd;
		break;
	case '3':
		compareFunc = AlphaCompareFromEndIgnorePunc;
		break;
	case '4':
		compareFunc = LenghtCompare;
		break;
	case '5':
		compareFunc = LenghtCompareFromEnd;
		break;
	case '6':
		compareFunc = LenghtCompareFromEndIgnorePunc;
		break;
	case 'q':
		printf("Quitting...\n");
		return 0;
		break;
	default:
		printf("Unknown command\nQuitting...\n");
		return 0;
		break;
	}


	char** strings = (char**)calloc(stringsCount, sizeof(char*));
	if (strings == NULL) 
	{
		printf("Error in memory allocation\nQuitting...\n");
		return 0;
	}
	stringsCount = SplitToStrings(text, strings, '\n', true);


	qsort(strings, stringsCount, sizeof(strings[0]), compareFunc);


	WriteFile(OutFileName, strings, stringsCount);
	printf("Sorted successfully\n");
	printf("out.txt is sorted file\n");

	free(strings);
	free(text);
	return 0;
}

