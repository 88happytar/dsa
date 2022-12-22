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

Node* Concat(Node *p, Node *q){
    Node* third  = p;
    while(p->next != NULL){
        p= p->next;
    }
    p->next = q;
    return third;
}

Node* Merge(Node *p, Node *q)
{
    // init
    Node *last, *third;
    if(p->data < q->data) {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    // merge
    while(p && q) {
        if(p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    // when p or q has more nodes, copy over
    while (p!=NULL) {
        cout << "left over p="<<p->data<<endl;
        last->next = p;
        last = p;
        p = p->next;
        last->next = NULL;
    }
        
    while (q!=NULL) {
        cout << "left over q="<<q->data<<endl;
        last->next = q;
        last = q;
        q = q->next;
        last->next = NULL;
    }
    
    return third;
}

int main()
{
    int A[]={10,20,40,50,60};
    int B[]={15,18,25,30,48};
    Node* first = create(A,5);
    Display(first);
    Node* second = create(B,5);
    Display(second);

    cout << "Concat => " << endl;
    Node* thirdAfterConcat = Concat(first,second);
    Display(thirdAfterConcat);
    
    // re-init first and second 
    first = create(A,5);
    Display(first);
    second = create(B,5);
    Display(second);
    cout << "Merge => " << endl;
    Node* thirdAfterMerge = Merge(first,second);
    Display(thirdAfterMerge);

    return 0;
}

