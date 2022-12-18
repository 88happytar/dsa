#include <iostream>
#include <array>
using namespace std;

int simpleLinearSearch(int key, int array[], int arraySize) {
    int index = -1;
    for (int i = 0; i < arraySize; i++)
    {
        if (key == array[i])
        {          
            index = i;
            break;
        }
    }  
    return index;
}

void swap(int* x, int* y)
{  
    int temp = *x; // Store the value store at x in a variable temp   
    *x = *y; // Swapping of value
    *y = temp;
}

void display(int array[], int arraySize)
{
    for(int i=0; i<arraySize; i++)
    {
        cout << array[i] << ":";
    }
    cout << endl;
}

/**
It is observed that when searching for a key element, then there is a possibility for searching 
the same key element again and again. In such a case, Linear Search can be improved by using 
the following two methods: 
- Transposition
- Move to Front
*/
int linearSearchTransposition(int key, int array[], int arraySize) {
    int index = -1;
    for (int i = 0; i < 10; i++)
    {
        if (key == array[i])
        {          
            index = i;
            if(i>0) 
            {
                swap(array[i],array[i - 1]);
            }
            break;
        }
    }  
    display(array, arraySize);
    return index;
}

int main()
{
    int array[10] = {2, 4, 6, 8, 12, 3, 5, 7, 9, 1};
    int arraySize =10;
    int key;
    cout << "Enter a Key element ";
    cin >> key;

    //int index = simpleLinearSearch(key, array, arraySize);
    int index = linearSearchTransposition(key, array, arraySize);
    if (index!=-1) {
        cout << "The Key element is found at index of " << index << endl;
    } else {
        cout << "Key element not found" << endl;
    }

    return 0;
}