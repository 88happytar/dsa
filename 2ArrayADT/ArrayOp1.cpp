#include <iostream>
#include <cstring>
using namespace std;

class MyArray
{
    private:
        char* array;
        int size;
    public:
        MyArray() //Constructor
        {
            cout << "constructor() is called" << endl;
            size = 10;
            array = new char[size]{'t'};
        }
        
        MyArray(int size) //Parameterized Constructor
        {
            cout << "constructor(int size) is called" << endl;
            this->size = size;        
            array = new char[size]{'a','h'};
        }

        //Destructor as Dynamic memory is used
        ~MyArray() 
        {
            cout << "destructor is called" << endl;
            delete [] array;
        }

        void displayItem();
        void insertItem(int index, char x);
        char deleteItem(int index);
    };

void MyArray::displayItem()
{
    cout << "displayItem ... size=" << size << endl;
    for(int i=0; i<size; i++)
    {
        cout << array[i] << ":";
    }
    cout << endl;
}

void MyArray::insertItem(int index, char x)
{
    cout << "insertItem ...index=" << index << "...x=" << x << endl;
    if(index>=0 && index<=size)
    {
        for(int i=size-1;i>index;i--)
        {
            cout << "i=" << i << endl;
            array[i] = array[i-1];  
        }
        array[index] = x;
    } else {
        cout << "cannot insert index="+index << endl;
    }
}

char MyArray::deleteItem(int index)
{
    cout << "deleteItem ...index=" << index << endl;
    char x=0;

    if(index>=0 && index<size)
    {
        x=array[index];
        for(int i=index;i<size-1;i++)
        {
            array[i]=array[i+1];
        }           
    }
    return x;
}

int main()
{ 
    //MyArray arr;
    MyArray arr(8);
    arr.displayItem();

    arr.insertItem(0,'m');
    arr.insertItem(3,'c');
    arr.insertItem(5,'d');
    arr.displayItem();

    arr.deleteItem(0);
    arr.displayItem();

    return 0;
}