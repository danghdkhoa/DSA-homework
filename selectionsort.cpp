#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100  

void SelectionSort(int a[],int n)
{
    int min,i,j;
    for (i=0; i<n-1 ; i++)
    {
        min = i;
        for(j = i+1; j < n ; j++)
            if (a[j ] < a[min])
                min = j;
        swap(a[min],a[i]); 
    }
}


void Output(int A[], int N) {

    for (int i = 0; i < N; i++)
        cout<< A[i]<< " ";
           cout<<endl;
}

int main() {
    int A[]={12, 2, 12 ,30, 15, 12, 6, 4, 15 };
    int N=9; 
    SelectionSort(A,N);
    Output(A,N);
    return 0;
}
 