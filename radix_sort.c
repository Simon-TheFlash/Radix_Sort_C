#include <stdio.h>
#include <stdlib.h>


int getLargest(int *arr, int *data)  
{
    int biggest = arr[0];
    for(int i = 1; i < *data; i++)
    {
        if(arr[i] > biggest)
        {
            biggest = arr[i];
        }
    }
    return biggest;

}
int countOfBits(int num)
{
    int count = 0;
    for(int i = 0; i < 32; i++)
    {
        if((num >> i) & 1)
        {
            count = i;
        }
    }
    return count;
}

void redixSort(int *arr, int arrSize, int numOfBits)
{
    int *bucket0,*bucket1; //two buckets;

    for(int b = 0; b <= numOfBits; b++)
    {


        bucket0 = malloc(sizeof(int)*arrSize);
        bucket1 = malloc(sizeof(int)*arrSize);


        for(int i =0; i < arrSize; i++)
        {
            if((arr[i] >> b) & 1)
            {
                bucket1[i] = arr[i];bucket0[i] = -1;
                continue;
            }
            bucket0[i] = arr[i];bucket1[i] = -1;

        }

        int c = 0;
        for(int i = 0; i < arrSize; i++)
        {
            if(bucket0[i] >= 0)
            {
                arr[c] = bucket0[i];c++;
            }

        }


         for(int i = 0; i < arrSize; i++)
        {
            if(bucket1[i] >= 0)
            {
                arr[c] = bucket1[i];c++;
            }

        }

        free(bucket0);
        bucket0 = NULL;
        free(bucket1);
        bucket1=NULL;


    }

}
int main()
{
    unsigned int *data;
    data = malloc(sizeof(int)*100);  //allocate this amount of memory;
    int *size;
    size = malloc(sizeof(int));
    printf("ENTER THE COUNT OF INTEGERS YOU WOULD LIKE TO SORT: ");

    scanf("%d",size);

    printf("\nENTER POSITIVE ENTEGERS TO SORT (0+): ");
    for(int i =0; i < *size; i++)
    {
        scanf("%d",&data[i]);
    }

    int biggest = getLargest(data,size);
    int numOfBits = countOfBits(biggest);



    printf("THE UNSORTED ARRAY: ");
     for(int i = 0; i < *size;i++)
    {
        printf("%d ",data[i]);

    }


    redixSort(data,*size,numOfBits);
    printf("\nTHE SORTED ARRAY: ");
    for(int i = 0; i < *size;i++)
    {
        printf("%d ",data[i]);

    }
    printf("\n");


    free(size);
    size = NULL;
    free(data);
    data = NULL;




}
