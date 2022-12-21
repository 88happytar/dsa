#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* create(int A[], int n)
{
    //Create a first node dynamically
    Node* first = new Node;
    first->data = A[0];
    first->next = NULL;
    Node* last = first;

    Node* temp;
    for(int i=1; i<n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    return first;
}

int max(Node* p)
{
    int maxNumber=-1000;
    while(p)
    {
        if(p->data > maxNumber){
            maxNumber = p->data;
        }     
        p = p->next;
    }
    return maxNumber;
}

int recursiveMax(Node* p)
{
    int x=0;
    if(p == 0)
        return -1000;

    x=recursiveMax(p->next);
    if(x>p->data)
        return x;
    else
        return p->data;
}

int main()
{
    int A[] = {3,5,7,10,25,8,32,2};
    Node* first = create(A,8);
   
    int maxResult = max(first);
    cout << "max Linked List => max=" << maxResult << endl;

    int maxResult1 = recursiveMax(first);
    cout << "recursiveMax Linked List => max=" << maxResult1 << endl;

    return 0;
}