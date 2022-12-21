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

Node* linearSearch(Node* p, int key){
    while(p != NULL)
    {
        if(key == p->data)
        {
            return (p);
        }   
        p = p->next;
    }
    return NULL;
}

// linearSearch; and move to head so later search for the key will be faster
Node* LSearch(Node* p, int key)
{
    Node* first = p;
    Node* q = NULL;
    while(p != NULL)
    {
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return first;
        }

        //q is a tail pointer that follows p
        q = p;
        p = p->next;
    }
    return NULL;
}

Node* recursiveSearch(Node* p, int key)
{
    if(p == NULL)
    {
        return NULL;
    }       
    if(key == p->data)
    {
        return p;
    }  
    return recursiveSearch(p->next,key);
}

int main()
{
    int A[] = {3,5,7,10,25,8,32,2};
    Node* first = create(A,8);
    cout << "Display Linked List => ";
    Display(first);

    Node* result = linearSearch(first,25);
    if(result)
        cout << "linearSearch Linked List => result=" << result->data << endl;
    else
        cout << "linearSearch Linked List key not found"<<endl;

    Node* result2 = recursiveSearch(first,25);
    if(result2)    
        cout << "recursiveSearch Linked List => result=" << result2->data << endl;
    else
        cout << "recursiveSearch Linked List key not found"<<endl;

    first = LSearch(first,25);
    cout << "Display Linked List after LSearch => ";
    Display(first);
    if(first)
        cout << "LSearch Linked List => result=" << first->data << endl;
    else
        cout << "LSearch Linked List key not found"<<endl;

    

    return 0;
}
