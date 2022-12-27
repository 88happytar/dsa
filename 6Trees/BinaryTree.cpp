#include<iostream>
#include<queue> 
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    Node(int data)
    {
        this->data = data;
        this->lchild = this->rchild=NULL;
    }
}; 

class Tree
{
private:
    Node *root;
public:
    Tree(Node *root)
    {
        this->root=root;
    }
    //void CreateTree();
    void Preorder()
    {
        Preorder(root);
    }
    void Preorder(Node *p);
    void Postorder()
    {
        Postorder(root);
    }
    void Postorder(Node *p);
    void Inorder()
    {
        Inorder(root);
    }
    void Inorder(Node *p);
    void Levelorder()
    {
        Levelorder(root);
    }
    void Levelorder(Node *p);
    int Height()
    {
        return Height(root);
    }
    int Height(Node *root);
    int Count()
    {
        return Count(root);
    }
    int Count(Node *root);
};

void Tree::Preorder(Node *p)
{
    if(p) {
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p)
{
    if(p) {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if(p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void Tree::Levelorder(Node *p)
{
    queue<Node*> q;
    printf("%d ",root->data);
    q.push(root);
    while(!q.empty()) {
        root = q.front();
        q.pop();
        if(root->lchild) {
            printf("%d ",root->lchild->data);
            q.push(root->lchild);
        }
        if(root->rchild) {
            printf("%d ",root->rchild->data);
            q.push(root->rchild);
        }
    }
}

int Tree::Height(Node *root)
{
    int x=0,y=0;
    if(root==NULL)
        return 0;
    x=Height(root->lchild);
    y=Height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

int Tree::Count(Node *root)
{
    if(root)
        return Count(root->lchild)+Count(root->rchild)+1;
    return 0;
}

int main()
{
    //Tree t;
    //t.CreateTree();

    /*
                 10
            2            3
          7   8      12     15
                          14
    */
    Node* root = new Node(10);
    Tree t(root);
    root->lchild = new Node(2);
    root->rchild = new Node(3);
    root->lchild->lchild = new Node(7);
    root->lchild->rchild = new Node(8);
    root->rchild->lchild = new Node(12);
    root->rchild->rchild = new Node(15);
    root->rchild->rchild->lchild = new Node(14);

    cout<<"Preorder ";
    t.Preorder();
    cout<<endl;

    cout<<"Inorder ";
    t.Inorder();
    cout<<endl;

    cout<<"Postorder ";
    t.Postorder();
    cout<<endl;

    // node 10 is root
    cout<<"Height ";
    cout << t.Height() <<endl;

    cout<<"count ";
    cout << t.Count() <<endl;

    cout<<"levelorder ";
    t.Levelorder();
    cout<<endl;

    // node 14 is at bottom
    cout<<"Current height level ";
    cout << t.Height() <<endl;

    return 0;
}