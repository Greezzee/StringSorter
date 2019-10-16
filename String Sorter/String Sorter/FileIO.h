#pragma once
/*!****************************************************
 * Get size of the file in bytes
 *
 * @param [in] file File to find size
 *
 * @return file size in bytes (count of chars)
 ******************************************************/
long getFileSize(FILE* file)
{
	fseek(file, 0, SEEK_END);
	long FileSize = ftell(file);
	fseek(file, 0, SEEK_SET);
	return FileSize;
}


/*!****************************************************
 * Read information from the file
 *
 * @param [in] InFileName Name/path of file with input information
 * @param [out] stringsCount number of strings in file
 *
 * @return ptr to all file's text in one string
 *
 * @note use free() to returned ptr after use
 ******************************************************/

char* ReadFile(const char* inFileName, long* stringsCount)
{
	assert(stringsCount != NULL);

	FILE* inFile = fopen(inFileName, "rb");

	if (inFile == NULL)
	{
		printf("Error, file doesn't exist\n");
		return NULL;
	}

	int fileSize = getFileSize(inFile);
	char* text = (char*)calloc(fileSize, sizeof(char));
	if (text == NULL)
	{
		printf("Error in memory allocation\n");
		return NULL;
	}
	fread(text, 1, fileSize, inFile);

	*stringsCount = 1;
	for (int i = 0; text[i] != '\0'; i++)
		if (text[i] == '\n')
			(*stringsCount)++;

	fclose(inFile);
	return text;
}

/*****************************************************
 * Write text to the file line by line
 *
 * @param [in] outFileName Name/path of file to write
 * @param [in] text Text to write
 * @param [in] stringsCount number of string to write
 ******************************************************/

void WriteFile(const char* outFileName, char** text, long stringsCount)
{
	assert(outFileName != NULL);
	assert(text != NULL);

	FILE* outFile = fopen(outFileName, "w");

	assert(outFile != NULL);
	for (int i = 0; i < stringsCount; i++) {
		fprintf(outFile, "%s\n", text[i]);
	}
	fclose(outFile);
}