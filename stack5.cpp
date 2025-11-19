
#include <iostream>
#include <iomanip>
using namespace std;

struct NODE_CHAR{
    char info;
    NODE_CHAR *pNext;
};

struct stack{
    NODE_CHAR *top;
};
NODE_CHAR *CreateNode(float x){
    NODE_CHAR *p=new NODE_CHAR;
    p->info=x;
    p->pNext=NULL;
    return p;
}

int getPriority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

NODE_CHAR* input_infix() {
    char op1, op2;
    cin >> op1 >> op2;

    NODE_CHAR* head = CreateNode(op1);
    head->pNext = CreateNode(op2);

    return head;
}

NODE_CHAR* infix_to_postfix(NODE_CHAR* infix) {
    if (infix == NULL || infix->pNext == NULL) return NULL;


    char op1 = infix->info;
    char op2 = infix->pNext->info;

    int p1 = getPriority(op1);
    int p2 = getPriority(op2);
    char relation;

    if (p1 > p2) relation = '>';
    else if (p1 < p2) relation = '<';
    else relation = '=';

    NODE_CHAR* resHead = CreateNode(op1);
    NODE_CHAR* curr = resHead;

    curr->pNext = CreateNode(' ');
    curr = curr->pNext;

    curr->pNext = CreateNode(relation);
    curr = curr->pNext;


    curr->pNext = CreateNode(' ');
    curr = curr->pNext;

    curr->pNext = CreateNode(op2);

    return resHead;
}

void out(NODE_CHAR* head) {
    NODE_CHAR* p = head;
    while (p != NULL) {
        cout << p->info;
        p = p->pNext;
    }
}
int main() {
    NODE_CHAR *infix=NULL;
    NODE_CHAR *postfix;

    infix=input_infix();

    postfix=infix_to_postfix(infix);
    out(postfix);
    return 0;
}
