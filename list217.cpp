
#include <iostream>
using namespace std;

struct DONTHUC{
    float HeSo;
    int SoMu;
};
struct NODE {
	DONTHUC info;
	NODE* pNext;
};
struct DATHUC {
	NODE* pHead;
	NODE* pTail;
};


void CreateEmptyDATHUC(DATHUC &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

void CreatePolynomial(DATHUC &L) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        float heso;
        int somu;
        cin >> heso >> somu;
        if (heso == 0) continue;

        NODE* p = L.pHead;
        NODE* q = NULL;
        while (p != NULL && p->info.SoMu < somu) {
            q = p;
            p = p->pNext;
        }

        if (p != NULL && p->info.SoMu == somu) {
            p->info.HeSo += heso;
            if (p->info.HeSo == 0) {
                if (q == NULL) {
                    L.pHead = p->pNext;
                    if (L.pHead == NULL) L.pTail = NULL;
                }
                else {
                    q->pNext = p->pNext;
                    if (q->pNext == NULL) L.pTail = q;
                }
                delete p;
            }
        }
        else {
            NODE* temp = new NODE;
            temp->info.HeSo = heso;
            temp->info.SoMu = somu;
            temp->pNext = p;
            if (q == NULL) L.pHead = temp;
            else q->pNext = temp;
            if (p == NULL) L.pTail = temp;
        }
    }
}



void Output(DONTHUC a){
    if(a.HeSo==-1) cout << "-";
	else if(a.HeSo==1) cout << "";
	else cout << a.HeSo;

    if(a.SoMu==0) cout << "";
	else if(a.SoMu==1) cout << "x";
	else if(a.SoMu<1) cout << "-x";
    else // s.SoMu>1
		cout << "x^" << a.SoMu;
}

void Output(DATHUC L) {
	NODE* p;

	if (L.pHead == NULL)
		cout << "Empty DATHUC.";
	else {
		p = L.pHead;
		Output(p->info);
		p=p->pNext;
		while (p) {
			cout << " + "; Output(p->info);
			p = p->pNext;
		}
	}
}

int main() {
    DATHUC poly;
	CreateEmptyDATHUC(poly);
    CreatePolynomial(poly);
	Output(poly);
	return 0;
}
