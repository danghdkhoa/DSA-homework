#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100
#define min(x,y) (x > y) ? y : x
int B[MAX], C[MAX];

void Merge(int A[], int nB, int nC, int k) {
	int p,pb,pc,ib,ic;
	p=pb=pc=ib=ic=0;
	int kb=min(k, nB), kc=min(k, nC);
	while ((nB > 0) && (nC > 0)) {
		if (B[pb+ib] <= C[pc+ic]) {
			A[p++]=B[pb+ib]; 
			ib++;
			if (ib == kb) {
				for (; ic<kc; ic++) A[p++] = C[pc+ic];
				pb+=kb;pc+=kc; 
				ib=ic=0;
				nB-=kb;nC-=kc;
				kb = min(k, nB); kc = min(k, nC);
            }
		}
		else {
			A[p++]=C[pc+ic]; 
			ic++;
			if (ic == kc) {
				for (; ib<kb; ib++) A[p++] = B[pb+ib];
				pb+=kb;pc+=kc; 
				ib=ic=0;
				nB-=kb;nC-=kc;
				kb = min(k, nB); kc = min(k, nC);
            }
		}
    }
}

void MergeSort(int A[], int n)
{
	int p, pb, pc, i, k = 1;
	while (k < n) {
		p = pb = pc = 0;
		while (p < n) {
			for (i=0; (p<n) && (i<k); i++) B[pb++]=A[p++];
			for (i=0; (p<n) && (i<k); i++) C[pc++]=A[p++];
        }
        Merge(A, pb, pc, k);
        k *= 2;
    }
}

void Output(int A[], int N) {

    for (int i = 0; i < N; i++)
        cout<< A[i]<< " ";
           cout<<endl;
}

int main() {
    int A[]={12, 2, 18,30, 5, 1, 6, 4, 15 };
    int N=9; 
    MergeSort(A,N);
    Output(A,N);
    return 0;
}