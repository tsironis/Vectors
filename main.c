/* 
 * The argument of this program are sth like this:
 * First argument: integer
 *		is the size of the vector
 * Second argument: integer (again...)
 *		is the element you're looking for inside the vector (binary search)
 * Third argument: -l
 *		tells the program to run in library mode, using our vector.h library
 * -------------------------------------------------------------------------------- 
 * Feel free to include any other arguments, they'll be ignored.
 */

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include <time.h>

#define initialCapacity 12

void printlist (IntVectorPtr vector, int n)
{
	int i;
    for(i=0;i<n-1;i++){
        printf("%d\t", vector->data[i]);	
    }
    printf("%d\n", vector->data[n]);
}

int main(int argc, char** argv)
{	
	int i;
 	int sz = atoi(argv[1]);
 	int element = atoi(argv[2]);
 	srand( (unsigned)time( NULL ));

	IntVectorPtr vector = VecNew(initialCapacity);

	for(i=0;i<sz+1;i++)
		vector = VecAdd(vector,rand()%100);

	printlist(vector, sz);

	if (argc == 3)
	{	
		VecQuickSort(vector);
		printf("\nThe position of the number %d is %d\n", element, VecBinarySearch(vector, element));
	} else if ( strcmp(argv[3], "-l") == 0 )
	{
		VecQuickSort2(vector, 1, sz-1);
		printf("\nThe position of the number %d is %d\n", element, VecBinarySearch2(vector->data, 0, sz, element));	
	}
		
		
	printlist(vector, sz);

	VecDelete(vector);
	return 0;
}


