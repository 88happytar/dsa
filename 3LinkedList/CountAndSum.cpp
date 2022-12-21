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

//TC=O(n), SC = O(1)
int count(Node* p)
{
    int l = 0;
    while(p != NULL)
    {
        l++;
        p = p->next;
    }
    return l;
}

//TC=O(n), SC = O(n)
int recursiveCount(Node* p)
{
    if(p != NULL){
        return recursiveCount(p->next)+1;
    }
    else 
    {
        return 0;
    }    
}

int sum(Node* p)
{
    int s = 0;
    while(p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int recursiveSum(Node *p)
{
    if(p == NULL)
    {
        return 0;
    }       
    else
    {
        return recursiveSum(p->next) + p->data;
    }
        
}

int main()
{
    int A[] = {3,5,7,10,25,8,32,2};
    Node* first = create(A,8);
   
    int sumResult = sum(first);
    cout << "sum Linked List => sum=" << sumResult << endl;

    int sumResult1 = recursiveSum(first);
    cout << "recursiveSum Linked List => sum=" << sumResult1 << endl;

    int countResult = count(first);
    cout << "count Linked List => countResult=" << countResult  << endl;

    int countResult1 = recursiveCount(first);
    cout << "recursiveCount Linked List => countResult=" << countResult1  << endl;

    return 0;
}