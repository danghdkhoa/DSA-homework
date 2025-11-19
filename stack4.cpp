
#include <iostream>
using namespace std;
#define MAXN 100

struct NODE{
    char info;
    NODE *pNext;
};
#include <stack>


bool isOperator(char x){
    return ( (x=='-') || (x=='+')|| (x=='*') || (x=='/') || (x=='^') );
}

int priority(char op) {
    if (op == '^') {
        return 3;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

void Input_infix(char infix[], int &n) {
    char k;
    n = 0;
    while (true) {
        cin >> k;
        if (k == '#') break;
        infix[n++] = k;
    }
}

void infix_to_postfix(char infix[], int ni, char postfix[], int &np) {
    stack<char> s;
    np = 0;
    for (int i = 0; i < ni; i++) {
        char c = infix[i];

        if (c >='0' && c <= '9') {
            postfix[np++] = c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!empty(s) && (char)s.top() != '(') {
                postfix[np++] = (char)s.top();
                s.pop();
            }
            if (!empty(s)) {
                s.pop();
            }
        } else if (isOperator(c)) {
            while (!empty(s) && (char)s.top() != '(' && priority((char)s.top()) >= priority(c)) {
                postfix[np++] = (char)s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!empty(s)) {
        postfix[np++] = (char)s.top();
        s.pop();
    }
}

void Output(char postfix[], int np) {
    for (int i = 0; i < np; i++) {
        cout << postfix[i] << " ";
    }
}

int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
