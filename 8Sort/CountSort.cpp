#include<iostream>
using namespace std;

int findMax(int A[],int n)
{
    int max=-999;
    int i;
    for(i=0; i<n; i++) {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}

void CountSort(int A[],int n)
{
    int i,j,max,*C;
    max=findMax(A,n);
    C=(int *)malloc(sizeof(int)*(max+1));
    for(i=0; i<max+1; i++) {
        C[i]=0;
    }
    for(i=0; i<n; i++) {
        C[A[i]]++;
    }
    i=0;
    j=0;
    while(j<max+1) {
        if(C[j]>0) {
            A[i++]=j;
            C[j]--;
        } else
            j++;
    }
}

int main()
{
    int A[]= {11,13,7,12,16,9,24,5,10,3};
    int n=10;
    CountSort(A,n);

    for(int i=0; i<10; i++)
        cout << A[i] << ":";
    cout << endl;

    return 0;
}
