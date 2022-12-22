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

void Display(Node* p)
{
    while(p!=NULL)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}

int isSorted(struct Node *p)
{
    int x = 0;
    while(p!=NULL){
        if(p->data < x)
        {
            return 0;
        }   
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main()
{
    int A[]={3,5,7,10,25,8,32,2};
    // int A[]={2, 3,5,7,8,10,25,32};
    
    Node* first = create(A,8); 
    Display(first);

    int result = isSorted(first);
    cout << "isSorted = "<< result;
    
    return 0;
}

