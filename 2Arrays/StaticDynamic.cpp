#include <iostream>
using namespace std;

int main()
{
    int aArray[5]={2,4,6,8,10}; // Static arry in stack
    int *bArray = new int[5]{3,5,7,9,11}; // Dynamic array in heap
    int i;

    // 
    for(i=0;i<5;i++) 
    {
        cout << aArray[i] << " ";
    }
    cout << endl;

    // 
    for(i=0;i<5;i++)
    {
        cout << bArray[i] << " ";
    }
    cout << endl;
    delete [] bArray;

    // determine array size uring run time
    int size;
    cin >> size;
    int *cArray = new int[size]{0};
    for(i=0;i<size;i++)
    {
        cout << cArray[i] << " " << endl;
    }
    delete [] cArray;

    return 0;
}