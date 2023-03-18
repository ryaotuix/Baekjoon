#include <stdio.h>
#include <stdlib.h>

#define VECTOR_INIT_CAPACITY 10
#define UNDEFINE -1
#define SUCCESS 0
#define VECTOR_INIT(vec) vector vec;\
vector_init(&vec);

typedef struct sVectorList
{
    void ** items;
    int capacity;
    int total;
} sVectorList;

typedef struct sVector vector;

struct sVector
{
    sVectorList vectorList;
    // function pointers?!
    int (*pfVectorTotal) (vector *);
    int (*pfVectorResize) (vector *, int);
    int (*pfVectorAdd) (vector *, void *);
    int (*pfVectorSet) (vector *, int, void *);
    void * (*pfVectorGet) (vector *, int);
    int (*pfVectorDelete) (vector *, int);
    int (*pfVectorFree) (vector *);
    void (*pfVectorInfo) (vector *);
};

int vectorTotal(vector *v)                          // Let's get capacity instead
{
    int totalCount = UNDEFINE;
    if(v)
    {
        totalCount = v->vectorList.capacity;
    }
    return totalCount;
}

int vectorResize(vector *v, int capacity)
{
    int  status = UNDEFINE;
    if(v)                                                                                               // pointer is 0 when it is not initialized when it is freed
    {
        void **items = realloc(v->vectorList.items, sizeof(void *) * capacity);
        if (items)
        {
            v->vectorList.items = items;
            v->vectorList.capacity = capacity;
            status = SUCCESS;
        }
    }
    return status;                      // return UNDEFINE when it is failed to resize, and SUCCESS otherwise
}


int vectorPushBack(vector *v, void *item)
{
    int  status = UNDEFINE;
    if(v)
    {
        if (v->vectorList.capacity == v->vectorList.total)                                             // If it is full
        {
            status = vectorResize(v, v->vectorList.capacity * 2);                                      // make it twice as large
            if(status != UNDEFINE)                                                                     // if succesfully resize then,
            {
                v->vectorList.items[v->vectorList.total++] = item;                                     // add item into a vector and increment total
            }
        }
        else
        {
            v->vectorList.items[v->vectorList.total++] = item;                                         // add item into a vector and increment total
            status = SUCCESS;
        }
    }
    return status;         
}

int vectorSet(vector *v, int index, void *item)
{
    int  status = UNDEFINE;
    if(v)
    {
        if ((index >= 0) && (index < v->vectorList.total))                                              // if the index is in the boundary
        {
            v->vectorList.items[index] = item;                                                          
            status = SUCCESS;
        }
    }
    return status;
}

void *vectorGet(vector *v, int index)
{
    void *readData = NULL;
    if(v)
    {
        if ((index >= 0) && (index < v->vectorList.total))
        {
            readData = v->vectorList.items[index];
        }
    }
    return readData;
}


// This is sexy as FUCK
int vectorDelete(vector *v, int index)
{
    int  status = UNDEFINE;
    int i = 0;
    if(v)
    {
        if ((index < 0) || (index >= v->vectorList.total))
            return status;
        v->vectorList.items[index] = NULL;
        for (i = index; (i < v->vectorList.total - 1); ++i)
        {
            v->vectorList.items[i] = v->vectorList.items[i + 1];
            v->vectorList.items[i + 1] = NULL;
        }
        v->vectorList.total--;


        if ((v->vectorList.total > 0) && ((v->vectorList.total) == (v->vectorList.capacity / 4)))            // Also change the capacity if we are only using 1/4 of it
        {
            vectorResize(v, v->vectorList.capacity / 2);
        }
        status = SUCCESS;
    }
    return status;
}

int vectorFree(vector *v)
{
    int  status = UNDEFINE;
    if(v)
    {
        free(v->vectorList.items);
        v->vectorList.items = NULL;
        status = SUCCESS;
    }
    return status;
}

void vectorInfo(vector * v)
{
    // Not INIT Case
    if (!v)
    {
        printf("It is not initialized\n");
        printf("\n");
        return;
    }


    // Once it is INIT,
    if (v->vectorList.items != NULL) {
        int i;
        // first print out the vector list 
        printf("Vector : [");
        for (i = 0; i < v->pfVectorTotal(v); ++i)
        {
            if (i == v->pfVectorTotal(v)-1)
                printf("%d", (int *)v->pfVectorGet(v, i));
            else
                printf("%d, ", (int *)v->pfVectorGet(v, i));
        }
        printf("]\n");

        // print capacity and total
        printf("Capacity : %d and Total : %d\n", v->vectorList.capacity, v->vectorList.total);
    }
    else
    {
        printf("It is freed\n");
    }
    printf("\n");
}


// initialize
void vector_init (vector * v)
{
    // init function pointers in vector structure
    v->pfVectorTotal = vectorTotal;
    v->pfVectorResize = vectorResize;
    v->pfVectorAdd = vectorPushBack;
    v->pfVectorSet = vectorSet;
    v->pfVectorGet = vectorGet;
    v->pfVectorFree = vectorFree;
    v->pfVectorDelete = vectorDelete;
    v->pfVectorInfo = vectorInfo;

    // init vectorList
    v->vectorList.capacity = VECTOR_INIT_CAPACITY;
    v->vectorList.total = 0;
    v->vectorList.items = malloc(sizeof(void *) * (v->vectorList.capacity));
}


int main()
{
    // init
    VECTOR_INIT(v);
    v.pfVectorAdd(&v, (void* ) 1);
    v.pfVectorAdd(&v, (void* ) 2);
    v.pfVectorAdd(&v, (void* ) 3);
    v.pfVectorAdd(&v, (void* ) 4);
    v.pfVectorAdd(&v, (void* ) 5);
    v.pfVectorAdd(&v, (void* ) 6);
    v.pfVectorAdd(&v, (void* ) 7);
    v.pfVectorAdd(&v, (void* ) 8);
    v.pfVectorAdd(&v, (void* ) 9);
    v.pfVectorAdd(&v, (void* ) 10);
    v.pfVectorAdd(&v, (void* ) 11);


    int i;
    v.pfVectorInfo(&v);


    v.pfVectorSet(&v, 0, (void *) 100);
    v.pfVectorInfo(&v);

    v.pfVectorDelete(&v, 1);
    v.pfVectorInfo(&v);

    v.pfVectorFree(&v);
    v.pfVectorInfo(&v);

    vector * v2 = 0;
    printf("%X %X", v2, &v2);
    vectorInfo(v2);
    printf("is it accessed\n");


}