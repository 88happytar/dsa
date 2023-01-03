//BST Insert and Search
#include <iostream>
using namespace std;

struct Node {
    Node *lchild;
    int data;
    Node *rchild;
}*root=NULL;

void Insert(int key)
{
    Node *t=root;
    Node *r=NULL,*p;

    //p for creating a new node
    //r will follow t
    if(root==NULL) {
        p=new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }

    while(t!=NULL) {
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else
            //suppose if key element is found, return
            return;
    }

    p=new Node;
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data)
        r->lchild=p;
    else
        r->rchild=p;
}

void Inorder(Node *p)
{
    if(p) {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

Node * Search(int key)
{
    Node *t=root;
    while(t!=NULL) {
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return NULL;
}

int main()
{
    Node *temp;
    Insert(50);
    Insert(10);
    Insert(40);
    Insert(20);
    Insert(30);
    //Delete(30);

    Inorder(root);
    printf("\n");

    temp=Search(20);
    if(temp!=NULL)
        printf("Element %d is found\n",temp->data);
    else
        printf("Element is not found\n");

    return 0;
}