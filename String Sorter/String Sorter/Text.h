#pragma once

/*!****************************************************
 * Split one string into several with char terminator
 *
 * @param [in,out] text Input string to split.
 * @param [out] Array for splitted strings, should have enought size
 * @param [in] terminator Char by whitch strings will split
 *
 * @return Count of strings after split
 *
 * @note all terminators in input string will replace to '\0'
 ******************************************************/

long SplitToStrings(char* text, char** strings, const char terminator, bool spaceIgnore = false)
{
	assert(text != NULL);
	assert(strings != NULL);
	strings[0] = text;
	long stringsCount = 1;
	long strLenght = 0;
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (spaceIgnore && isspace(text[i]) && strLenght == 0) {
			text[i] = '\0';
			if (stringsCount > 0) strings[stringsCount - 1]++;
		}

		else if (text[i] == '\r') text[i] = ' ';

		else if (text[i] == terminator)
		{
			text[i] = '\0';
			strings[stringsCount] = text + i + 1;
			stringsCount++;
			strLenght = 0;
		}
		else strLenght++;
	}
	return stringsCount - 1;
}