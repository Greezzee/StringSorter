#pragma once

/*!****************************************************
 * Compare strings lexicographically
 *
 * @param [in] string1,string2 strings to compare
 *
 * @return number, sign of which show, whitch string is "bigger"
 ******************************************************/

int AlphaCompare(const void* string1, const void* string2)
{
	const char* str1 = *(const char**)string1;
	const char* str2 = *(const char**)string2;
	int out = 0;
	long i = 0;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] > str2[i]) return 1;
		else if (str1[i] < str2[i]) return -1;
	}

	if (str1[i] == '\0' && str2[i] != '\0') return 1;
	else if (str1[i] != '\0' && str2[i] == '\0')  return -1;
	else return 0;
}

/*!****************************************************
 * Compare strings lexicographically, but start from end os strings
 *
 * @param [in] string1,string2 strings to compare
 *
 * @return number, sign of which show, whitch string is "bigger"
 ******************************************************/

int AlphaCompareFromEnd(const void* string1, const void* string2)
{
	const char* str1 = *(const char**)string1;
	const char* str2 = *(const char**)string2;
	int out = 0;
	long i = 0, j = 0;

	if (strlen(str1) == 0) return 1;
	if (strlen(str2) == 0) return -1;

	i = strlen(str1) - 1;
	j = strlen(str2) - 1;

	while (isspace(str1[i]) && i > 0) i--;
	while (isspace(str2[j]) && j > 0) j--;

	for (i, j; i >= 0 && j >= 0; i--, j--)
	{
		if (str1[i] > str2[j]) return 1;
		else if (str1[i] < str2[j]) return -1;
	}
	return i - j;
}

/*!****************************************************
 * Compare strings lexicographically, but start from end os strings. Ignore all punct in string's end.
 *
 * @param [in] string1,string2 strings to compare
 *
 * @return number, sign of which show, whitch string is "bigger"
 ******************************************************/

int AlphaCompareFromEndIgnorePunc(const void* string1, const void* string2)
{
	const char* str1 = *(const char**)string1;
	const char* str2 = *(const char**)string2;
	int out = 0;
	long i = 0, j = 0;

	if (strlen(str1) == 0) return 1;
	if (strlen(str2) == 0) return -1;

	i = strlen(str1) - 1;
	j = strlen(str2) - 1;

	while ((ispunct(str1[i]) || isspace(str1[i])) && i > 0) i--;
	while ((ispunct(str2[j]) || isspace(str2[j])) && j > 0) j--;

	for (i, j; i >= 0 && j >= 0; i--, j--)
	{
		if (str1[i] > str2[j]) return 1;
		else if (str1[i] < str2[j]) return -1;
	}
	return i - j;
}

/*!****************************************************
 * Compare strings by lenght. If strings have equal lenght, compare lexicographically
 *
 * @param [in] string1,string2 strings to compare
 *
 * @return number, sign of which show, whitch string is "bigger"
 ******************************************************/

int LenghtCompare(const void* string1, const void* string2)
{
	const char* str1 = *(const char**)string1;
	const char* str2 = *(const char**)string2;
	if (strlen(str1) == 0) return 1;
	if (strlen(str2) == 0) return -1;
	if (strlen(str1) - strlen(str2) == 0) return AlphaCompare(string1, string2);
	return strlen(str1) - strlen(str2);
}

/*!****************************************************
 * Compare strings by lenght. If strings have equal lenght, compare lexicographically
 *
 * @param [in] string1,string2 strings to compare
 *
 * @return number, sign of which show, whitch string is "bigger"
 ******************************************************/

int LenghtCompareFromEnd(const void* string1, const void* string2)
{
	const char* str1 = *(const char**)string1;
	const char* str2 = *(const char**)string2;
	if (strlen(str1) == 0) return 1;
	if (strlen(str2) == 0) return -1;
	if (strlen(str1) - strlen(str2) == 0) return AlphaCompareFromEnd(string1, string2);
	return strlen(str1) - strlen(str2);
}

/*!****************************************************
 * Compare strings by lenght. If strings have equal lenght, compare lexicographically
 *
 * @param [in] string1,string2 strings to compare
 *
 * @return number, sign of which show, whitch string is "bigger"
 ******************************************************/

int LenghtCompareFromEndIgnorePunc(const void* string1, const void* string2)
{
	const char* str1 = *(const char**)string1;
	const char* str2 = *(const char**)string2;
	if (strlen(str1) == 0) return 1;
	if (strlen(str2) == 0) return -1;
	if (strlen(str1) - strlen(str2) == 0) return AlphaCompareFromEndIgnorePunc(string1, string2);
	return strlen(str1) - strlen(str2);
}
