#ifndef _INTVECTOR_H

#define TRUE 1
#define FALSE 0

typedef struct {
	int size;
	int capacity;
	int *data;
} IntVector, *IntVectorPtr;

IntVectorPtr VecNew(int initialCapacity);

void VecDelete(IntVectorPtr vector);

#define VecGetSize(v) ((v)->size);

#define VecGetCapacity(v) ((v)->capacity)
#define VecIsFull(v) (((v)->capacity) == ((v)->size) ? TRUE : FALSE)

IntVectorPtr VecAdd(IntVectorPtr vector, int element);

int VecErase(IntVectorPtr vector, int position);

int VecMin(int *vector, int size);

int VecMax(int *vector, int size);

double VecAvg(int *vector, int size);

#define VecGet (v, p) ((v)->data[p])

#define swap(a,b)({int temp;temp=a;a=b;b=temp;})

void VecQuickSort (IntVectorPtr vector);

void VecQuickSort2 (IntVectorPtr vector, int low, int high);

int VecBinarySearch (IntVectorPtr vector, int element);

int VecBinarySearch2 (int *vector, int low, int high, int element);

#endif 
