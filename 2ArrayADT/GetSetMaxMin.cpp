
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

//Get the value of an element at a particular Index
int get(int array[], int arraySize, int index)
{
    if(index>=0 && index<arraySize)
    {
        return array[index];
    }
    return -1;
}

//Replace or Overrite the value at a particular index
//TC=O(n)
void set(int array[], int arraySize, int index, int x)
{
    if(index>=0 && index<arraySize)
    {
        array[index]=x;        
    }
}

//For unsorted list I have to check all elements
//TC=O(n)
int max(int array[], int arraySize)
{
    int max=array[0];
    int i;
    for(i=1;i<arraySize;i++)
    {
        if(array[i]>max) {
            max=array[i];
        }      
    }
    return max;
}

//For unsorted list I have to check all elements
//f(n)=2n + 1
int min(int array[], int arraySize)
{
    int min=array[0];
    int i;
    for(i=1;i<arraySize;i++)
    {
        if(array[i]<min)
        {
            min=array[i];
        }
    }
    return min;
}

int sum(int array[], int arraySize)
{
    int s=0;
    int i;
    for(i=0; i<arraySize; i++)
    {
       s+=array[i];    
    }
    return s;
}

float avg(int array[], int arraySize)
{
    return (float)sum(array, arraySize)/arraySize;
}

int main()
{
    int intArray[] = {2,3,9,16,18,21,28,32,35};
    int arraySize = 9;
    display(intArray, arraySize);  

    int maxVal = max(intArray, arraySize);
    cout << "max=" << maxVal << endl;

    int minVal = min(intArray, arraySize);
    cout << "min=" << minVal << endl;

    int sumVal = sum(intArray, arraySize);
    cout << "sum=" << sumVal << endl;

    float avgVal = avg(intArray, arraySize);
    cout << "avg=" << avgVal << endl;

    int val = get(intArray, arraySize, 4);
    cout << "at index 4, val=" << val << endl;

    set(intArray, arraySize, 4, 10);
    cout << "array after set => "; 
    display(intArray, arraySize); 

    return 0;
}