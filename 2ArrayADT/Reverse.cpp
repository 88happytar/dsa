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

void reverse(int intArray[], int arraySize)
{
    int i,j;
    int intArrayNew[arraySize] = {};

    for(i=arraySize-1,j=0; i>=0; i--,j++)
    {
        intArrayNew[j]=intArray[i];
    }
        
    for(i=0;i<arraySize;i++)
    {
        intArray[i]=intArrayNew[i];
    }    
}

void reverse2(int intArray[], int arraySize)
{
    int i,j;
    for(i=0,j= arraySize-1; i<j; i++,j--)
    {
        swap(&intArray[i], &intArray[j]);
    }
}

int main()
{
    int intArray[] = {2,3,9,16,18,21,28,32,35};
    int arraySize = 9;
    display(intArray, arraySize);  

    //reverse(intArray, arraySize);
    //cout << "After reverse => ";
    //display(intArray, arraySize);

    reverse2(intArray, arraySize);
    cout << "After reverse2 => ";
    display(intArray, arraySize);

    return 0;
}
