#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Bubble(int A[],int n)
{
    int i,j,flag=0;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        //'-i' as in every pass 'i' comparisons are reduced.
        for(j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        //If already sorted list, no swapping req in any pass
        if(flag==0)
            break;
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3};
    int n=10;
    Bubble(A,n);

    for(int i=0;i<10;i++)
        cout << A[i] << ":";
    cout << endl;

    return 0;
}