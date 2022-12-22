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

int isLoop(Node *first)
{
    Node *p,*q;
    p = q = first;
    do {
        p = p->next;
        q = q->next;
        q = q!=NULL ? q->next : NULL;
    } while(p && q && p!=q);

    if(p == q)
        return 1;
    else
        return 0;
}

int main()
{
    int A[] = {10,20,30,40,50};
    Node* first = create(A,5);

    Node *t1,*t2;
    t1 = first->next->next;
    cout << "display t1 => ";
    Display(t1);
    t2 = first->next->next->next->next;
    cout << "display t2 => ";
    Display(t2);
    t2->next = t1; //We made a loopN

    cout << "isLoop = " << isLoop(first);

    return 0;
}
