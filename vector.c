#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int int_cmp (const void *a, const void *b)
{
  return ( *(int*)a - *(int*)b);
}

int choosepivot(int i, int j)
{
    return ((i+j)/2);
}

IntVectorPtr VecNew(int initialCapacity)
{
    IntVectorPtr pVec = (IntVectorPtr) malloc(sizeof(IntVector));

    if (NULL == pVec)
        return NULL;

    pVec->data = (int *) malloc(initialCapacity*sizeof(int));
    if (NULL == pVec->data)
    {
        free(pVec);

        return NULL;
    }

    pVec->size = 0;
    pVec->capacity = initialCapacity;

    return pVec;
}


IntVectorPtr VecAdd (IntVectorPtr pVec, int element )
{
	IntVectorPtr vec=pVec;
    if (vec->size == vec->capacity)
    {
        int *newData = (int *)realloc(vec->data,vec->capacity*2*sizeof(int));

        if (NULL == newData)
            return NULL;

        vec->data = newData;
        vec->capacity *= 2;
    }

    vec->data[vec->size] = element;
    vec->size++;
    return vec;
}

int VecMax (int *pVec, int size)
{
    int i;
    int max = pVec[0];

    for (i=0; i<size; i++)
    {
        if (pVec[i]>max)
            max = pVec[i];
    }
    return max;
}

int VecMin (int *pVec, int size)
{
    int i;
    int min = pVec[0];

    for (i=0; i<size; i++)
    {
        if (pVec[i]<min)
            min = pVec[i];
    }
    return min;
}

double VecAvg (int *pVec, int size)
{
    int i;
    int sum=0;
    int s = size;
    for (i=0; i<size; i++)
    {
        sum += pVec[i];
    }
    return  sum/(double)s;
}

int VecErase (IntVectorPtr pVec, int pos)
{
	if (pos<=pVec->size)
	{
		pVec->data[pos]=pVec->data[pVec->size];
		pVec->size--;
	}
	else 
		return -1;
}

void VecDelete (IntVectorPtr pVec)
{
	free(pVec);
}

void VecQuickSort(IntVectorPtr pVec)
{
	qsort(pVec->data, pVec->size, sizeof(int), int_cmp);
}

void VecQuickSort2(IntVectorPtr pVec, int low, int high)
{
	int key, i, j, k;

	if ( low < high )
	{
		k = choosepivot(low, high);

        swap(pVec->data[low], pVec->data[k]);

        key = pVec->data[low];
        i = low+1;
        j = high;

        while(i <= j)
        {
            while((i <= high) && (pVec->data[i] <= key))
                i++;
            while((j >= low) && (pVec->data[j] > key))
                j--;
            if( i < j)
                swap(pVec->data[i],pVec->data[j]);
        }
        swap(pVec->data[low], pVec->data[high]);

        VecQuickSort2(pVec, low, j-1);
        VecQuickSort2(pVec, j+1, high);
	}
}

int VecBinarySearch(IntVectorPtr pVec, int element)
{
	bsearch(&element, pVec->data, pVec->size, sizeof(int), int_cmp);
}

int VecBinarySearch2(int *pVec, int low, int high, int element)
{
    while (low <= high) {
        int middle = low + (high - low)/2;
        if (element > pVec[middle])
            low = middle + 1;
        else if (element < pVec[middle])
			high = middle - 1;
        else
            return middle;
    }
    return -1;
}


