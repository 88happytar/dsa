#include <iostream>
using namespace std;

int main()
{
    int i;  
    int *p = new int[5]; // create array in heap
    p[0]=3;p[1]=5;p[2]=7;p[3]=9;p[4]=11;
    int *q = new int[10]{0}; // create array in heap; Init all elements to be 0

    //
    for(i=0;i<5;i++) //Transfer element from 'p' to 'q'
    {
        q[i]=p[i];
    } 
    delete [] p; // Now free memory of old array in heap

    // 
    p=q; // Now point 'p' and  'q' to the same location
    q=NULL; // Now delete the value of q pointing to the memory location
    for(i=0;i<10;i++)
    {
        cout << p[i] << " ";
    }
        
    return 0;
}