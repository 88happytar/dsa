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
}

//TC=O(n)
void RecursiveDisplay(Node* p)
{
    if(p!=NULL)
    {  
        cout << p->data << " ";
        RecursiveDisplay(p->next);
    }
}

void removeDuplicate(Node *p)
{
    Node *q = p->next;
    while(q!=NULL)
    {
        if(p->data != q->data) //if distinct
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q=p->next;
        }
    }
}

int main()
{
    int A[]={10,20,20,40,50,50,50,60};
    Node* first = create(A,8);
    
    cout << "Display Linked List => ";
    Display(first);   
    cout << endl;

    removeDuplicate(first);

    cout << "After ... Display Linked List => ";
    Display(first);   
    cout << endl;
    
    return 0;
}