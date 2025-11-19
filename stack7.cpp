#include <iostream>
using namespace std;
struct NODE{
    int info;
    NODE *pNext;
};
struct stack{
    NODE *top;
};

NODE* CreateNode(int x) {
    NODE *p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptyStack(stack &s) {
    s.top = NULL;
}

bool empty(const stack &s) {
    return s.top == NULL;
}

void push(stack &s, int x) {
    NODE *p = CreateNode(x);
    if (empty(s)) {
        s.top = p;
    } else {
        p->pNext = s.top;
        s.top = p;
    }
}

int top(stack s) {
    return s.top->info;
}

void pop(stack &s) {
    if (empty(s)) return;
    NODE *p = s.top;
    s.top = s.top->pNext;
    delete p;
}

void array_reverse(stack s, int a[], int &n) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        push(s, a[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << top(s) << " ";
        pop(s);
    }
}

int main() {
    stack s;
    int a[100], n;
    array_reverse(s,a,n);
    return 0;
}
