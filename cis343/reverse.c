/*
 *@Author: Tyler Bruder
 *@Version: Fall 2018
 *
 *
 * A small program that reads in a file, reverses the words and writes to a new file
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "file_utils.h"

//The input file is defined as 1, as the written output is 2.
#define INPUT_FILE 1
#define OUTPUT_FILE 2

//External int that will contain our error numbers if any come up
extern int errno;//Ideaology for the following worked on with Matt K

int main (int argc, char** argv) {

	char* buffer;

	// When calling the program, if arguements is not 3, show how proper syntax works
	if (argc != 3)
	{
		printf("Invalid syntax, please use: ./a.out [inputfile] [outputfile]\n");
		return EXIT_FAILURE;
	}
	
	// Gets the size of the file were reading
	int size = read_file(*(argv + INPUT_FILE), &buffer);

	//Error checking for any common errors, nothing specific Error checking discussed and worked on with Matt K
	if (errno != 0)
	{
		fprintf(stderr, "\n\nError present. errno is %d\n", errno);
		perror("Error");
		fprintf(stderr, "\n\n");
		return errno;
	}

	//Allocate memory for reversing the file
	char* bufferRev = (char*)malloc(size * sizeof(char));
	for (int i = 0; i < size; i++)
		bufferRev[size - 1 - i] = buffer[i];

	//Rewriting to the file after the words have been reversed
	write_file (*(argv + OUTPUT_FILE), bufferRev, size);

	//More error checking once the file has been written to
	if (errno != 0)
	{
		fprintf(stderr, "\n\nError present. errno is %d\n", errno);
		perror("Error");
		fprintf(stderr, "\n\n");
		return errno;
	}

	//Clears / frees memory and makes it available again
	free(bufferRev);
	free(buffer);
	return EXIT_SUCCESS;
}
