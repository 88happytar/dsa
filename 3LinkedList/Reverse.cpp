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

void Reverse1(Node *first)
{
    Node *q = first;
    int* A =(int*)new int[5];

    //Copy from LL to Array
    int i = 0;
    while(q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    q = first; // point back to head node
    i--;

    //Copy from Array back to LL in a reverse manner
    while(q!=NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

//Using Sliding pointers, q-> node to be modified, p-> next node, r-> previous node
Node* Reverse2(Node *p)
{
    Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;//Reverse the link
    }
    return q;
}

// Using Recursion
Node* Reverse3(Node *q, Node *p)
{
    Node* first;
    if(p!= NULL)
    {
        Reverse3(p,p->next);
        //At returning time, links will be reversed
        p->next=q;
    }
    else
    {
        first=q;
    }
    return first;
}


int main()
{
    int A[]={10,20,40,50,60};
    Node *first = create(A,5);
    Display(first);

    // inplace replacement, so the content of first are changed
    Reverse1(first);
    Display(first);

    // rebuild the link list
    cout << "Reconstruct linked list " << endl;
    Node *firstNew = create(A,5);
    Node *firstAfter2 = Reverse2(firstNew);
    Display(firstAfter2);

    Node *firstAfter3 = Reverse3(NULL,firstNew);
    Display(firstAfter3);

    return 0;
}
