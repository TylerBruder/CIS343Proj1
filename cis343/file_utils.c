/*
 *@Author: Tyler Bruder
 *@Version: Fall 2018
 *
 *A small program that will read in a file, reverse the words in it, and write it to a new file
 *
 */


#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int read_file (char* filename, char **buffer) {
	//A File pointer that will point to the file we are reading
	FILE *fin = fopen(filename, "r");
	char temp;
	
	//If the file was not able to be read, or does not exist, return error code
	if (fin == NULL)
		return errno;
	
	struct stat st;
	stat(filename, &st);
	//Gather file size
	int size = st.st_size;

	char* tempBuff;
	int curr = 0;
	//Gathering size of the data
	tempBuff = (char *)malloc(size * sizeof(char));
	
	while (fscanf(fin, "%c", &temp) != EOF)
		tempBuff[curr++] = temp;

	//Get the size of the file after it has all been read into the buffer
	*buffer = tempBuff;
	fclose(fin);
	return size;
}

	//Write file to the new file
int write_file( char* filename, char *buffer, int size) {
	FILE *fout = fopen (filename, "w");
	//Printing words oone at a time
	for (int i = 0; i < size; i++)
		fprintf(fout, "%c", buffer[i]);

	fclose(fout);
	return errno;
}
