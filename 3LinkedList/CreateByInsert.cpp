#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void Display(Node* p)
{
    while(p!=NULL)
    {
        cout << p->data << " ";
        p=p->next;
    }
}

Node* findLastNode(Node* head)
{
    Node* temp = head;

    if (temp->next == NULL)
        return head;
 
    // Traverse the linked list
    while (temp != NULL) {
        // Check if the current node  is the last node or not
        if (temp->next == NULL)
            return temp;
 
        // If not then move to the next node
        temp = temp->next;
    }
}

Node* Insert(Node *first, int index, int x)
{
    Node *t = new Node;
    t->data = x;
    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        Node* p = first;
        for(int i=0; i<index-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
    return first;
}

Node* Insertlast(Node *first, int x){
    Node *t = new Node;
    t->data = x;
    t->next = NULL;

    Node* last = findLastNode(first);

    if(first == NULL){
        first = t;
        last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
    return first;
}

int main()
{
    //start with empty list
    Node* first = NULL;
    
    first = Insert(first,0,15);
    first = Insert(first,0,8);
    first = Insert(first,0,9);
    first = Insert(first,1,10);
    cout << "After Insert => ";
    Display(first);
    cout << endl;

    first = Insertlast(first, 20);
     first = Insertlast(first, 23);
    cout << "After Insertlast => ";
    Display(first);
    cout << endl;

    return 0;
}
