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

int binarySearch(int array[], int arraySize, int key)
{
    int l,mid,h;
    l = 0;
    h = arraySize-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key == array[mid])
        {
            return mid;
        } else if(key < array[mid])
        {
            h=mid-1;
        } else
        {
            l=mid+1;
        }   
    }
    return -1;
}

int binarySearch2(int a[], int l, int h, int key)
{
    int mid=0;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
        {
            return mid;
        } else if(key<a[mid])
        {
            return binarySearch2(a,l,mid-1,key);
        } else
        {
            return binarySearch2(a,mid+1,h,key);
        }
    }      
    return -1;
}

int main()
{
    int intArray[] = {2,3,9,16,18,21,28,32,35};
    int arraySize = 9;
    display(intArray, arraySize);  
    int key = 16;

    // method 1
    //int index = binarySearch(intArray, arraySize, key);

    // method 2
    int index = binarySearch2(intArray, 0, arraySize-1, key);

    if (index!=-1) {
        cout << "The Key " << key << " is found at index of " << index << endl;
    } else {
        cout << "The Key " << key << " is not found" << endl;
    }

    return 0;
}