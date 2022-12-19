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

void insertSort(int array[], int arraySize, int x)
{
    int i= arraySize-1;
    while(i>=0 && array[i]>x)
    {
        array[i+1]= array[i];
        i--;
    }
    array[i+1]=x;
    arraySize++;
}

int isSorted(int array[], int arraySize)
{
    int i;
    for(i=0; i<arraySize-1; i++)
    {
        if(array[i]>array[i+1])
        return 0;
    }
    return 1;
}

int main()
{
    int intArray[] = {2,3,9,16,18,21,28,31,35}; // only init 9
    int arraySize = 10;
    display(intArray, arraySize);  

    insertSort(intArray, arraySize, 25);
    cout << "array after insertSort => "; 
    display(intArray, arraySize); 

    int isSortedVal = isSorted(intArray, arraySize);
    cout << "isSortedVal=" << isSortedVal;

    return 0;
}