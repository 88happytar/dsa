#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* lchild;
    Node* rchild;
};

class BST
{
public:
    void display(Node *p)
    {
        if(p) {
            display(p->lchild);
            cout<<p->data<<" ";
            display(p->rchild);
        }
    }
};

class Stack
{
public:
    int length;
    int top;
    Node **s;
    Stack()
    {
        top=-1;
        length=100;//length should be intialised
        s=new Node*[100]; // array for storing nodes should be created
    }
    BST m;
    void push(Node *p)
    {
        if(top==length-1)return;
        s[++top]=p;
    }
    Node* pop()
    {
        if(top==-1)return NULL;
        return s[top--];
    }
    int stacktop()
    {
        if(top!=-1)return s[top]->data;
        return 100000;
    }
    void createpre(int a[],int n);
    bool isstackempty()
    {
        if(top==-1)return 1;
        return 0;
    }
};

void Stack::createpre(int a[],int n)
{
    Node *p,*t;
    int i=0;
    Node* root=new Node;
    root->data=a[i++];
    root->lchild=root->rchild=nullptr;
    p=root;
    while(i<n) {
        if(a[i] < p->data) {
            t=new Node;
            t->data=a[i++];
                t->lchild=t->rchild=nullptr;
                p->lchild=t;
                push(p);
                p=t;
        } else {
            if(a[i]>p->data && a[i]<stacktop()) {
                t=new Node;
                t->lchild=t->rchild=nullptr;
                t->data=a[i++];
                p->rchild=t;
                p=t;
            } else {
                p=pop();
            }
        }
    }
    cout << "generated BST disply => ";
    m.display(root);
}

int main()
{
    int a[]= {30,20,10,15,25,40,50,45};
    Stack st;
    st.top=-1;
    st.length=sizeof(a)/sizeof(a[0]);
    st.createpre(a,st.length);
    return 0;
}