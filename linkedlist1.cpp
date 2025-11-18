#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct LIST {
   Node *pHead;
   Node *pTail;
};

void CreateEmptyList(LIST  &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

void AddHead(LIST &L, Node *p) {
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = L.pHead;
    } else {
        p->next = L.pHead;
        L.pHead = p;
    }
}

void AddTail(LIST &L, Node*p) {
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = L.pHead;
    } else {
        L.pTail->next = p;
        L.pTail = p;
    }
}

void AddAfterQ(LIST &L, Node *p, Node *Q) {
    if (Q != NULL) {
        p->next = Q->next;
        Q->next = p;
        if (L.pTail == Q) {
            L.pTail = p;
        }
    }
}

void CreateList(LIST &L) {
    int n;
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        } else {
            Node *p = new Node;
            p->data = n;
            p->next = NULL;
            AddTail(L, p);
        }
    }
}


bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= n; i+= 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
void add_after_all_prime(LIST &L, int Y) {
    Node *p = L.pHead;

    while (p != NULL) {
        if (isPrime(p->data)) {
            Node *q = new Node;
            q->data = Y;
            q->next = NULL;

            AddAfterQ(L, q, p);

            p = q->next;
        } else {
            p = p->next;
        }
    }

}

void add_afterX_1(LIST &L, int Y, int X) {
    Node *p = L.pHead;

    while (p != NULL) {
        if (p->data == X) {
            Node *q = new Node;
            q->data = Y;
            q->next = NULL;

            AddAfterQ(L, q, p);

            p = q->next;
            break;
        } else {
            p = p->next;
        }
    }
}

int getSize(LIST &L) {
    int size = 0;
    Node *p = L.pHead;

    while (p != NULL) {
        size++;
        p = p->next;
    }
    return size;
}
void add_after_k_th(LIST &L,int Y,int k) {
    int n = 1;
    Node *q = L.pHead;
    int size = getSize(L);
    if (k > size || k < 1) {
        return;
    }
    while (n++ < k) {
        q = q->next;
    }
    Node *p = new Node;
    p->data = Y;
    p->next = NULL;
    AddAfterQ(L, p, q);
}

void PrintList(LIST &L) {
    Node *p = L.pHead;
    if (L.pHead == NULL) {
        cout << "Empty List.";
        return;
    }
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

void PrintList(Node *pHead) {
    Node *p = pHead;

    if (p == NULL) {
        cout << "Empty List.";
        return;
    }
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}


void PrintList_Odd(Node *pHead) {
    Node *p = pHead;
    if (p == NULL) {
        cout << "Empty List.";
        return;
    }
    int count = 0;
    while (p != NULL) {
        if (p->data % 2 != 0) {
            cout << p->data << " ";
            count++;
        }
        p = p->next;
    }
    if (count == 0) {
        cout << "Không có số lẻ trong mảng.";
    }
}

void PrintList_Prime(LIST &L) {
    Node *p = L.pHead;
    if (p == NULL) {
        cout << "Empty List.";
        return;
    }
    int count = 0;
    while (p != NULL) {
        if (isPrime(p->data)) {
            cout << p->data << " ";
            count++;
        }
        p = p->next;
    }
    if (count == 0) {
        cout << "Không có số nguyên tố trong mảng.";
    }
}

void PrintReverse(Node *p) {
    if (p == NULL) return;
    PrintReverse(p->next);
    cout << p->data << " ";
}

void PrintListReverseOrder(LIST &L) {
    if (L.pHead == NULL) {
        cout << "Empty List.";
        return;
    }
    PrintReverse(L.pHead);
}


int power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power(x, y/2) * power(x, y / 2);
    }
    return x * power(x, y /2) * power(x, y / 2);
}

int order(int n) {
    int t = 0;
    while (n) {
        t++;
        n = n / 10;
    }
    return t;
}

bool amstrong(int n) {
    int x = order(n);
    int temp = n, sum = 0;
    if (n <= 0) {
        return false;
    }
    while (temp) {
        int r = temp % 10;
        sum += power(r, x);
        temp = temp / 10;
    }
    return (sum == n);
}

void PrintList_Armstrong(LIST &L) {
    Node *p = L.pHead;
    if (p == NULL) {
        cout << "Empty List.";
        return;
    }
    int count = 0;
    stack<int> reversed;
    while (p != NULL) {
        if (amstrong(p->data)) {
            reversed.push(p->data);
            count++;
        }
        p = p->next;
    }
    if (count == 0) {
        cout << "Không có số armstrong trong mảng.";
        return;
    }
    while (!reversed.empty()) {
        cout << reversed.top() << " ";
        reversed.pop();
    }
}

string searchX(Node *pHead, int x) {
    Node *p = pHead;
    while (p != NULL) {
        if (p->data == x) {
            return "true";
        }
        p = p->next;
    }
    return "false";
}




int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList_Armstrong(L);

    return 0;
}
