//Queue using Linked List
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *front=NULL,*rear=NULL;

void enqueue(int x)
{
    Node *t = new Node;
    if(t==NULL)
        printf("Queue is FUll\n");
    //Only if the Heap in memory is full and no new node can't be created.
    else {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            //If first Node
            front=rear=t;
        else {
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue()
{
    int x=-1;
    Node* t;
    if(front==NULL)
        printf("Queue is Empty\n");
    else {
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}

void display()
{
    Node *p=front;
    while(p) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    dequeue();
    display();

    return 0;
}
