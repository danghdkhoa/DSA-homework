#include <iostream>
using namespace std;

struct NODE {
    int data;
    NODE *pNext;
};

struct LIST {
    NODE *pHead;
    NODE *pTail;
};

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

void AddHead(LIST &L, NODE *p) {
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = p;
    } else {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

void AddTail(LIST &L, NODE *p) {
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = L.pHead;
    } else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}


bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= n; i+=2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int search_prime(NODE *pHead) {
    NODE *p = pHead;
    int idx = 1;
    while (p != NULL) {
        if (isPrime(p->data)) {
            return idx;
        }
        idx++;
        p = p->pNext;
    }
    return 0;
}

int count_even(NODE *pHead) {
    NODE *p = pHead;
    int count = 0;
    while (p != NULL) {
        if (p->data % 2 == 0) {
            count++;
        }
        p = p->pNext;
    }
    return count;
}

int length(LIST &L) {
    NODE *p = L.pHead;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->pNext;
    }
    return count;
}

int length(NODE *pHead) {
    NODE *p = pHead;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->pNext;
    }
    return count;
}

NODE* RemoveHead(LIST &L) {
    if (L.pHead == NULL) {
        return NULL;
    }
    NODE *temp = L.pHead;
    L.pHead = L.pHead->pNext;
    delete temp;
    if (L.pHead == NULL) {
        L.pTail = NULL; 
    }
    
    return L.pHead;
}

NODE* RemoveTail(LIST &L) {
    if (L.pHead == NULL) {
        return NULL;
    }
    if (L.pHead->pNext == NULL) {
        delete L.pHead;
        L.pHead = NULL;
        L.pTail = NULL;
        return NULL;
    }
    
    NODE *secondLast = L.pHead;
    while (secondLast->pNext->pNext != NULL) {
        secondLast = secondLast->pNext;
    }
    delete secondLast->pNext;
    secondLast->pNext = NULL;
    return L.pHead;
}


NODE* RemoveX(LIST &L, int X) {
    if (L.pHead == NULL) {
        return NULL;
    }
    
    if (L.pHead->data == X) {
        RemoveHead(L);
        return L.pHead;
    }
    
    NODE *p = L.pHead;
    while (p->pNext != NULL) {
        if (p->pNext->data == X) {
            NODE* n2delete = p->pNext;
            p->pNext = n2delete->pNext;
            
            if (n2delete == L.pTail) {
                L.pTail = p;
            }
            delete n2delete;
            return NULL;
        }
        p = p->pNext;
    }
    return L.pHead;
}

void PrintList(LIST &L) {
    NODE *p = L.pHead;
    if (p == NULL) {
        cout << "Empty List.";
    }
    while (p != NULL) {
        cout << p->data << " ";
        p = p->pNext;
    }
}


void Nhap(LIST &L) {
    int n;
    cin >> n;
    for (int i = 0; i < n * 2; i++) {
        int x;
        cin >> x;
        NODE *p = new NODE;
        p->data = x;
        p->pNext = NULL;
        AddTail(L, p);
    }
}

void Xuat(LIST &L) {
    NODE *p = L.pHead;
    while (p != NULL) {
        cout << "(" << p->data << ", " << p->pNext->data << ")" << endl;
        p = p->pNext->pNext;
    }
}

void AddAfterQ(LIST &L, NODE *p, NODE *Q) {
    if (Q != NULL) {
        p->pNext = Q->pNext;
        Q->pNext = p;
        if (L.pTail == Q) {
            L.pTail = p;
        }
    }
}

NODE* FindNode(LIST L, int x) {
    NODE* temp = L.pHead;
    while (temp != NULL) {
        if (temp->data == x) {
            return temp;
        }
        temp = temp->pNext;
    }
    return NULL;
}

void CreateList(LIST &L) {
    // int n;
    // while (true) {
    //     cin >> n;
        
    //     if (n == -1) {
    //         break; 
    //     }
    //     if (n == 0) {
    //         int x;
    //         cin >> x;
    //         NODE *p = new NODE;
    //         p->data = x;
    //         p->pNext = NULL;
    //         AddHead(L, p);
    //     }

    //     else if (n == 1) {
    //         int x;
    //         cin >> x; 
    //         NODE *p = new NODE;
    //         p->data = x;
    //         p->pNext = NULL;
    //         AddTail(L, p);
    //     }
    //     else if (n == 2) {
    //         int x, y;
    //         cin >> x >> y; 

    //         NODE *q = L.pHead;
    //         while (q != NULL) {
    //             if (q->data == x) {
                    
    //                 NODE *p = new NODE;
    //                 p->data = y;
    //                 p->pNext = NULL;
                    

    //                 AddAfterQ(L, p, q);
    //                 break; 
    //             }
    //             q = q->pNext;
    //         }
    //     }
    // }
    int n;
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        } else {
            NODE *p = new NODE;
            p->data = n;
            p->pNext = NULL;
            AddTail(L, p);
        }
    }
}

void add_after_middle(LIST &L, int Y) {
    if (L.pHead == NULL) {
        return;
    }
    int n = length(L);
    int k = (n - 1) / 2;

    NODE* pNode = L.pHead;
    for (int i = 0; i < k; i++) {
        pNode = pNode->pNext;
    }


    NODE* pNew = new NODE;
    pNew->data = Y;
    pNew->pNext = NULL;


    AddAfterQ(L, pNew, pNode);
}

bool isPerfect(long long n) {
    if (n <= 1) return false;
    long long sum = 1;
    
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) sum += n / i;
        }
    }
    return sum == n;
}

void count_perfect_number(NODE *pHead, int &count) {
    count = 0;
    while (pHead != NULL ) {
        if (isPerfect(pHead->data)) {
            count++;
        }
        pHead = pHead->pNext;
    }
}


void Function(NODE *head) {
    if (head == NULL) {
        cout << "Empty List." << endl;
        return;
    }

    NODE* current = head;

    while (current != NULL) {
        int x = current->data;
        int y = -1; 

        NODE* checker = current->pNext;
        
        while (checker != NULL) {
            if (checker->data < x) {
                y = checker->data;
                break; 
            }
            checker = checker->pNext;
        }
        
        cout << x << " " << y << endl;
        current = current->pNext;
    }
}

void Print_Middle(LIST &L) {
    if (L.pHead == NULL) {
        cout << "Empty List.";
        return;
    }
    int n = length(L);
    int k = (n - 1) / 2;

    NODE* pNode = L.pHead;
    for (int i = 0; i < k; i++) {
        pNode = pNode->pNext;
    }
    cout << pNode->data;
}

void Remove_k_th(LIST &L, int k) {
    if (L.pHead == NULL || k < 1) return;

    if (k == 1) {
        RemoveHead(L);
        return;
    }

    NODE *pTemp = L.pHead;
    for (int i = 1; i < k - 1; i++) {
        if (pTemp == NULL) return;
        pTemp = pTemp->pNext;
    }

    if (pTemp == NULL || pTemp->pNext == NULL) return;

    NODE *pDel = pTemp->pNext;
    pTemp->pNext = pDel->pNext;

    if (pDel == L.pTail) {
        L.pTail = pTemp;
    }

    delete pDel;
}


int main() {
    LIST L;
	int k;
	CreateEmptyList(L);

	CreateList(L);
	std::cin >> k;
	Remove_k_th(L, k);
    PrintList(L);

    return 0;
}


