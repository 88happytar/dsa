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

/**
Stack vs Heap Pros and Cons

=========================
Stack
=========================
very fast access
don't have to explicitly de-allocate variables
space is managed efficiently by CPU, memory will not become fragmented
local variables only
limit on stack size (OS-dependent)
variables cannot be resized

=========================
Heap
=========================
variables can be accessed globally
no limit on memory size
(relatively) slower access
no guaranteed efficient use of space, memory may become fragmented over time as blocks of memory are allocated, then freed
you must manage memory (you're in charge of allocating and freeing variables)
variables can be resized using realloc()
 
=========================
When to use the Heap?
=========================
When should you use the heap, and when should you use the stack? If you need to allocate a large block of memory 
(e.g. a large array, or a big struct), and you need to keep that variable around a long time (like a global), 
then you should allocate it on the heap. If you are dealing with relatively small variables that only need to 
persist as long as the function using them is alive, then you should use the stack, it's easier and faster. 
If you need variables like arrays and structs that can change size dynamically (e.g. arrays that can grow or 
shrink as needed) then you will likely need to allocate them on the heap.
*/