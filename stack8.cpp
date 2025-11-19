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

void BracketMatching(stack &s, char st[]) {
    CreateEmptyStack(s);
    
    
    cin.getline(st, 100);
    
    for (int i = 0; st[i] != '\0'; i++) {

        if (st[i] == '(') {
            push(s, '('); 
        } 

        else if (st[i] == ')') {

            if (empty(s)) {
                cout << "False";
                return;
            }
           
            else {
                pop(s);
            }
        }
    }

    if (empty(s)) {
        cout << "True";
    } else {
        cout << "False";
    }
}

int main() {
    stack s;
    char st[100];
    BracketMatching(s,st);
    return 0;
}
