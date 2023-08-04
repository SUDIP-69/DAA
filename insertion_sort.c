#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sort(int arr[],int n1)
{ 
    int i, key, j;
    for (i = 1; i < n1; i++)    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
    // for(int i=0;i<n1;i++)
    // printf("%d ",arr[i]);
}

void best(int a[],int len)
{
    // for(int i=0;i<len;i++)
    // printf("%d ",a[i]);
    // printf("\n");
    clock_t starttime = clock();
    sort(a,len);
    clock_t endtime = clock();
    float timetaken = (int)(endtime - starttime)*1000000/CLOCKS_PER_SEC;
    printf("\nBest Case:\t%0.2f micro-second\n",timetaken);
}

void avg(int a[],int len)
{
    // for(int i=0;i<len;i++)
    // printf("%d ",a[i]);
    // printf("\n");
    clock_t starttime = clock();
    sort(a,len);
    clock_t endtime = clock();
    float timetaken = (int)(endtime - starttime)*1000000/CLOCKS_PER_SEC;
    printf("\nAverage Case:\t%0.2f micro-second\n",timetaken);
}

void worst(int a[],int len)
{
    int r[len];
    for(int i=0;i<len;i++)
        r[len-i-1]=a[i];
    a=r;
    
    // for(int i=0;i<len;i++)
    // printf("%d ",a[i]);
    // printf("\n");
    clock_t starttime = clock();
    sort(a,len);
    clock_t endtime = clock();
    float timetaken = (int)(endtime - starttime)*1000000/CLOCKS_PER_SEC;
    printf("\nWorst Case:\t%0.2f micro-second\n",timetaken);
}

int main()
{
    int n=50000,i;
    int a[n];
    
    for(i=0;i<n;i++)
    {
        a[i]=rand() % 100;
    }
    
    avg(a,n);
    best(a,n);
    worst(a,n);

}