#include <stdio.h>
#include "headerfile.h"
int main( int argc, char** argv )
{
	if (argc != 2)
	{
	printf( "Sorry!!! Enter Image Name as a command line argument\n" );
	return - 1;
	}
	openImage(argv[1]);
	convertToGray(argv[1]);
	return 0;

}
