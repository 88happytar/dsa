#include <iostream>
using namespace std;

#define SIZE 10

int hashFunction(int key)
{
    return key%SIZE;
}

void displayItem(int array[])
{
    cout << "displayItem ... SIZE=" << SIZE << endl;
    for(int i=0; i<SIZE; i++)
    {
        cout << array[i] << ":";
    }
    cout << endl;
}

//Finds the next free space
int probe(int hashTable[], int key)
{
    int index = hashFunction(key);
    int i = 0;
    while(hashTable[(index+i)%SIZE]!=0)
        i++;
    return (index+i)%SIZE;
}

void Insert(int hashTable[],int key)
{
    int index = hashFunction(key);
    if(hashTable[index] != 0)
        index = probe(hashTable,key);
    hashTable[index] = key;
}

int Search(int hashTable[],int key)
{
    int index = hashFunction(key);
    int i=0;
    while(hashTable[(index+i)%SIZE]!=key)
        i++;
    return (index+i)%SIZE;
}

int main()
{
    int hashTable[SIZE]={0};
    Insert(hashTable,12);
    Insert(hashTable,25);
    Insert(hashTable,35);
    Insert(hashTable,26);

    displayItem(hashTable);

    printf("\nKey found at %d\n", Search(hashTable,35));
    return 0;
}