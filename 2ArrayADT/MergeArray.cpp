#include <iostream>
using namespace std;

void display(int array[], int arraySize)
{
    for(int i=0; i<arraySize; i++)
    {
        cout << array[i] << ":";
    }
    cout << endl;
}

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void mergeSort(int array[], int arraySize, int array2[], int arraySize2, int arrayMerged[])
{
    int i,j;
    for(i=0; i<arraySize; i++)
    {
        arrayMerged[i] = array[i];
    }
    for(j=0; j<arraySize2; j++)
    {
        arrayMerged[i] = array2[j];
        i++;
    }
    cout << "array after merge => "; 
    display(arrayMerged, arraySize+arraySize2);

    // sort
    int sizeMerge = i;
    for(j=0; j<(sizeMerge-1); j++)
    {
        for(i=0; i<(sizeMerge-1); i++)
        {
            if(arrayMerged[i]>arrayMerged[i+1])
            {
                swap(arrayMerged[i],arrayMerged[i+1]);
            }
        }
    }
}

int main()
{
    int intArray[] = {2,3,9,16,18,21,28,32,35};
    int arraySize = 9;
    cout << "array => ";  
    display(intArray, arraySize);  

    int intArray2[] = {13,15,33,38};
    int arraySize2 = 4;
    cout << "array2 => ";  
    display(intArray2, arraySize2);  

    int arrayMerged[arraySize+arraySize2];

    mergeSort(intArray, arraySize, intArray2, arraySize2, arrayMerged);
    cout << "array after mergeSort => "; 
    display(arrayMerged, arraySize+arraySize2); 

    return 0;
}
