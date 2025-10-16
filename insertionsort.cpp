#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100  

void insertionSort(int A[], int n) {
	for (int i = 1; i < n; i++)
    {
		int e = A[i]; int k;
		for (k = i-1; k>-1; k--) {
			if (A[k] < e) break;
			A[k+1] = A[k];
		}
		A[k+1] = e; 
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
    insertionSort(A,N);
    Output(A,N);
    return 0;
}
 