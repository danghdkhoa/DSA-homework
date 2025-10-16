#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100  

void quickSort(int *a, int b, int e) {
	if (b >= e) return;
	int x = a[(b+e)/2], i = b, j = e;
	while(i < j) {
		while (a[i] < x) i++; 
		while (a[j] > x) j--;
		if (i <= j) {
			swap(a[i], a[j]); i++; j--; }
	}
	quickSort(a, b, j); quickSort(a, i, e);
}


void Output(int A[], int N) {

    for (int i = 0; i < N; i++)
        cout<< A[i]<< " ";
           cout<<endl;
}

int main() {
    int A[]={12, 2, 18,30, 5, 1, 6, 4, 15 };
    int N=9; 
    quickSort(A,0,N-1);
    Output(A,N);
    return 0;
}
 