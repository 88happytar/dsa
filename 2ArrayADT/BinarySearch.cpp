#include <iostream>
using namespace std;

struct Array
{
    int A[9];
    int length;
};

void display(struct Array arr)
{
    int i;
    cout << "Elements are ";
    for(i=0;i<arr.length;i++) {
        cout << arr.A[i] << " ";
    } 
    cout << endl;   
}

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int binarySearch(struct Array arr, int key)
{
    int l,mid,h;
    l=0;
    h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
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
    struct Array arr1={{2,3,9,16,18,21,28,32,35},9};
    display(arr1);  
    int key = 16;

    // method 1
    //int index = binarySearch(arr1, key);

    // method 2
    int intArray[] = {2,3,9,16,18,21,28,32,35};
    int index = binarySearch2(intArray, 0, 8, key);

    if (index!=-1) {
        cout << "The Key " << key << " is found at index of " << index << endl;
    } else {
        cout << "The Key " << key << " is not found" << endl;
    }

    return 0;
}